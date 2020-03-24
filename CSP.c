/*************************************************************************/
//Author:     Vertika Srivastava
//File NAme:  CSP.c
//This program is to build the communication switch process and its function as the switch of the fast Ethernet. //Therefore CSP will give permission to a SP to send a frame, accept frames from a source station and
//forward each frame received to its destination station.
//Every time a request frame is received, the CSP will either send a reply to the SP so
//that the SP will send a frame, or hold it in its waiting queue if it is busy. When it receives
//a data frame it will inspect the destination address. It will then send out the frame to the
//destination station.
/**************************************************************************/


/**************Headers***********/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#define MAXSIZE 225
#define MAXSIZELINE 1024
#define SA struct sockaddr
#define size 25


/*structure for the frame */
struct frame
{
		int sequenceNo;
		int sourceAdd;
		int destinAdd;
		char data[MAXSIZE];		
};

/*structure for the client details */
struct clientAddr
{
		int descriptor;
		int stationNo;
};
//Declaring the global variables
int port_number;
int MAXSIZEi, MAXSIZEfd, listenfd, newsockfd, sockfd;
int frm_no,srcaddr,destaddr,i;
char data[MAXSIZE];
FILE *out; 
struct frame data_frame[size];
struct frame requ_frame[size];
struct clientAddr clientAddress[size];
int rfcnt, dfcnt;
char buff[MAXSIZELINE];
char buff_write[MAXSIZELINE];

/**
This function isto handle error and display error message.
**/
void handleError(const char *message,int code) 
{
	perror(message);
	exit(code);
}
void ProcessReq(char *buff, int i);


int main(int argc, char * argv[]) 
{
	socklen_t client_length;
	struct sockaddr_in serv_addr, cli_addr;
	int nready,client[FD_SETSIZE]; 
	fd_set rset, allset;
	int i, n, j;	
	
	
    if (argc != 2) 
	{
		printf("\n Please enter correct argumnets \n");
		exit(0);
	}
	port_number = atoi(argv[1]);//port number from user
	//the output file is opening in the write mode.	
	out = fopen("CSP_OUTPUT.txt", "w");
	

    if(out == NULL)
    {
		handleError("ERROR while opening the output file.",-1);
    }

	//creating the socket
	if((listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		handleError("Error opening server socket",1);
	}
	
	int flag = 1;	
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int)) == -1) 
	{
		handleError("ERROR",1);
	}
	
	//sets the entire structure to zero.
	//bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	
	//port_number is entered by user
	serv_addr.sin_port = htons(port_number);
	
	//Binding the socket.
	if (bind(listenfd, (SA *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		handleError("ERROR on binding",1);
	}	
	
	listen(listenfd, 10);

	MAXSIZEfd = listenfd; //initialize
	MAXSIZEi = -1;  /*index into client[] array*/
	
	
	for(i = 0; i < FD_SETSIZE; i++)
		client[i] = -1; //initialize the value to -1
	
	
	for(i = 0; i < size; i++)
	{
		clientAddress[i].descriptor = -1; 
		clientAddress[i].stationNo = -1;
	}
	
	
	/*Initializing the bot queues such as the data frame queue and request frame queue*/
	for(i=0; i < size; i++)
	{
		data_frame[i].sequenceNo = -1;
		data_frame[i].sourceAdd = -1;
		data_frame[i].destinAdd = -1;
		strcpy(data_frame[i].data," ");
		
		requ_frame[i].sequenceNo = -1;
		requ_frame[i].sourceAdd = -1;
		requ_frame[i].destinAdd = -1;
		strcpy(requ_frame[i].data," ");
	}
	


	//Initializes the file descriptor set to contain no file decriptors.
	FD_ZERO(&rset);	
	rfcnt = 0;
	dfcnt = 0;
	
	
	for(;;)
	{
          FD_SET(listenfd,&rset);
		
		//waiting for activities from station processes (multiplexing function)
		nready = select(listenfd+1, &rset, NULL, NULL, NULL);
		
		//new client connection
		if(FD_ISSET(listenfd, &rset))
		{
	       client_length = sizeof(cli_addr);		
			
			newsockfd = accept(listenfd, (SA *) &cli_addr, &client_length); //accepting clients
			
			printf("\nServer established connection with the client %s : %d",inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port));
			fflush(stdout);
			
			
			//The connection descriptor is placed in the client array.
			for(i=0; i < FD_SETSIZE; i++)
			{
				if(client[i] < 0)
				{
					client[i] = newsockfd;
					break;
				}
			}
			
			if(i == FD_SETSIZE)
			{
				//write log to file
				fprintf(out,"\n Only can accept 10 clients\n");
			}				
			
			
			if(newsockfd > MAXSIZEfd)
				MAXSIZEfd = newsockfd; //adjust the MAXSIZEfd of select function.
				
			//MAXSIZEimum array index of client 
			if (i > MAXSIZEi)
				MAXSIZEi = i;
			
			//if no more clients to read then continue
			if (--nready <= 0)
				continue;
		}
		
		//This performs checking all clients for data.
		for(i=0; i <= MAXSIZEi; i++) 
		{
			if((sockfd = client[i]) < 0)
				continue; 
			
			//checking is socket ready for read.
			if(FD_ISSET(listenfd, &rset))
			{

				if(( n = read(listenfd, buff, MAXSIZELINE)) == 0)
				{
					/* Connection closed by client */
					close(listenfd);
					FD_CLR(listenfd, &rset);
					client[i] = -1;
					
					/*Clearing the corresponding client addresses*/
					clientAddress[i].descriptor = -1;  
					clientAddress[i].stationNo = -1;
				}
				else
				{
					
					
					bzero(buff, sizeof(buff)); 			
					//reading  the frame
					sscanf(buff, "%d %d %d %s", &frm_no,&srcaddr,&destaddr,data);
					//printf("\nReading frame no:%d Source:%d  Dest:%d, Data:%s ", frm_no,srcaddr,destaddr,data);
					
					if((strcmp(data,"Request") == 0))
					{
						/*Map the client address with the corresponding descriptor*/
						
						if(clientAddress[i].descriptor < 0)/*only if the descriptor is empty*/
						{
							clientAddress[i].descriptor = client[i];
							clientAddress[i].stationNo = srcaddr;
						}
						
						//write log to file
						fprintf(out,"\nReceive request from SP%d\n",srcaddr);
							
						ProcessReq(buff, i);
						
						
						if((write(newsockfd, buff_write, strlen(buff_write))) < 0)
						{
							handleError("ERROR",2);
						}
						fprintf(out,"\nSent %s for Request Frame %d from SP%d  to SP%d\n", data, frm_no, srcaddr, destaddr);
						fflush(out);
						close(newsockfd);
					}
					else
					{
						//add data frame to queue.
						data_frame[dfcnt].sequenceNo = frm_no;
						data_frame[dfcnt].sourceAdd = srcaddr;
						data_frame[dfcnt].destinAdd = destaddr;
						strcpy(data_frame[dfcnt].data,data);
								
						dfcnt++;
					}					
				}
				
				if(--nready <= 0)
					break;
			}
		}
		
		/*Reading from queues and processing the frames accordingly*/
		if(nready <= 0)
		{
			/*Read from the dataframe and send it to the destination*/
		
			for(j=0; j < size; j++)
			{
				if(data_frame[j].sourceAdd > 0) //checking if frame present.
				{
					
					for(i = 0; i < MAXSIZEi+1; i++) /*iterating through clientAddress to get the descriptor details*/
					{
						if(clientAddress[i].stationNo == data_frame[j].destinAdd)
						{
							
							sprintf(buff_write, "%d %d %d %s \n", data_frame[j].sequenceNo, data_frame[j].sourceAdd, data_frame[j].destinAdd, data_frame[j].data);
							if((write(clientAddress[i].descriptor, buff_write, strlen(buff_write))) < 0)
							{
								handleError("ERROR writing to socket",3);
							}
							
							//write log to file
							fprintf(out,"\nForward data frame from SP%d to SP%d \n",data_frame[j].sourceAdd, data_frame[j].destinAdd);
							fflush(out);
							
							
						}
					}
				}
			}
			
			/*Read from the request frame and send appropriate reply*/
			for(j = 0; j < size; j++)
			{
				
				if(requ_frame[j].sourceAdd > 0) //request frame present?
				{
					
					sprintf(buff_write, "%d %d %d %s \n", requ_frame[j].sequenceNo, requ_frame[j].sourceAdd, requ_frame[j].destinAdd, requ_frame[j].data);
					sscanf(buff_write, "%d %d %d %s", &frm_no,&srcaddr,&destaddr,data);
					ProcessReq(buff_write, j);
					
				}
			}
		}
		else
			break;
	
	}
	// closing the output file
	fclose(out);
}


/*This function is to processes the requests from clients*/
void ProcessReq(char *buff, int i)
{
	if((strcmp(data,"Request") == 0))
	{				
		if(dfcnt < size)
		{
			strcpy(data, "Accept");
			sprintf(buff_write, "%d %d %d %s \n", frm_no, srcaddr, destaddr, data);
							
			//write log to file
			fprintf(out,"\nSent positive reply to SP%d\n",srcaddr);
		}
		else
		{
			if(rfcnt < size)
			{
				//add request frame to queue.
				requ_frame[rfcnt].sequenceNo = frm_no;
				requ_frame[rfcnt].sourceAdd = srcaddr;
				requ_frame[rfcnt].destinAdd = destaddr;
				strcpy(requ_frame[rfcnt].data,data);
								
				rfcnt++;
			}
			else
			{
				strcpy(data, "Reject");
				sprintf(buff_write, "%d %d %d %s \n", frm_no, srcaddr, destaddr, data);
								
				//write log to file
				fprintf(out,"\nSent reject to SP%d\n",srcaddr);
			}
							
		}
	}
}
