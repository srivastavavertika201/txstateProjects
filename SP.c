
/*************************************************************************/
//Author:     Vertika Srivastava
//File NAme:  SP.c

//This program is to build the station process.One station process for each simulated station.
//It performs mainly :- 
//(1) It reads a line from its simulation input data file and format it as a data frame.
//(2) It then sends a request frame to the CSP asking permission to send its data frame
//just formatted and wait for reply.
//(3) If it a reject reply from theh CSP, it has to retransmit the request frame.
//(4) If it a positive reply from theh CSP, it will then proceed to send data frame to the CSP.

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
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <stdbool.h>

#define MAXSIZE 225
#define MAXSIZELINE 1024
#define SA struct sockaddr

/*structure for the frame */
struct frame
{
		int sequenceNo;
		int sourceAdd;
		int destinAdd;
		char data[MAXSIZE];		
};

/************Declaring the global variables****/


int portno,sockfd,filefd;
struct sockaddr_in servaddr;
fd_set rset;
int MAXSIZEfdp1, nready;
int  stationNo;
int count = 0;
int frameNos = 0;
bool flag;
char sim_input[100];
char data[MAXSIZE];
char reply[MAXSIZE];
char sp1[10], sp2[10], sp3[10], sp4[10],sp5[10],sp5[10],sp6[10],sp7[10],sp8[10],sp9[10],sp10[10];
FILE *output_file;
FILE *file_data;
FILE *input_file;
int frm_no, destinationAdd; 
char write_buff[MAXSIZE];
char server_reply[MAXSIZE];




//A function to handle when an error occurs.
void HandleErrors(const char *message)
{
	perror(message);
	exit(0);
}


//A function is to send request frame to the communication switch process.
void requestFrame(char *buff)
{
	//Reading the data from input buffer
	sscanf(buff, "%s %d %s %s %s %s %s %s %s %d", sp1, &frm_no, sp2, sp3, sp4,sp5,sp6,sp7,sp8, &destinationAdd);
		
	//writing data into the output buffer
	strcpy(data,"Request");
	sprintf(write_buff, "%d %d %d %s \n", frm_no, stationNo, destinationAdd, data);	
		
	//sending request frame to the communication switch process
	if((write(sockfd, write_buff, strlen(write_buff))) < 0)
	{
		HandleErrors("ERROR writing to socket");
	}
	count++; 
	
	//writing the data into the outputfile
	fprintf(output_file,"\nSend request to CSP to send data frame %d to SP %d\n",frm_no,destinationAdd);
	
}

//A function is to read communication switch process reply and send Data frame
void DataFrame(char *buff)
{
		int r1, r2, r3;
		
		//read the communication switch process reply
		sscanf(server_reply, "%d %d %d %s", &r1,&r2,&r3,reply);
		
		//checking the communication switch process reply
		if(strcmp(reply,"Accept") == 0)
		{
			//Open the file in the read mode
			file_data = fopen("DataFile.txt" , "r");		
			bzero(data,MAXSIZE);
			if(file_data == NULL) 
			{
				//if the file is not opened then write log to file
				fprintf(output_file,"\nError opening data file\n");			
				strncpy(data,"No data found in the file.", MAXSIZE);
			}
			else
			{
				//Capturing the data form file into buffer
				fgets(data,MAXSIZE,file_data);
			}	
		
			//performs the writing function to write data into the buffer
			sprintf(write_buff, "%d %d %d %s \n", frm_no, stationNo, destinationAdd, data);	
			
			//sending the data frame to communication switch process.
			if (write(sockfd, write_buff, strlen(write_buff)) < 0)
			{
				HandleErrors("ERROR is occured while writing to socket");
			}
			//writing the data to the file
			fprintf(output_file,"\nSend data frame %d to SP %d \n",frm_no,stationNo);
			fflush(output_file);
			fclose(file_data);
		}
		else
		{
			if((strcmp(reply,"Reject") == 0))
			{
				if(count < 3)
				{
					count++;
					fprintf(output_file,"\nReject response from CSP to send data frame %d to SP %d\n",frm_no,destinationAdd);
					requestFrame(sim_input);//Performs resending the frame.
					
				}
				else
				{
					count = 0;
					fprintf(output_file,"\n Not able to connect.\n");
					HandleErrors("Currently server is down,Not able to send the frame.\n");
				}
			}
		}
		
		if( r3 == stationNo)
		{
			fprintf(output_file,"\nReceive a data frame from SP %d\n",r2);
			fflush(output_file);
		}
return;
}

//This function is to wait for the frames
bool frameWait(char *buff)
{
	int nframe;
	
	sscanf(buff, "%s %s %s %d %s", sp1, sp2, sp3, &nframe, sp4);
	
	if (frameNos >= nframe)
	{
		frameNos = 0; //making receievd farmes zero for next wait.
		return 1;
	}
	else
	{
		printf("\nWait till the frame has sent.\n", nframe);
		return 0;
	}	
}

//This function is to process the action based the input types
void ProcessRequests(char input_line[])
{
	if(strstr(input_line, "SP") != "\0") 
	{
		requestFrame(input_line); //type of frame is Request
	}
	else 
	{
		if(strstr(input_line, "Wait") != "\0")
		{
			flag = frameWait(input_line);
		}
	}
		
}

int main(int argc, char *argv[])
{
	//check arguments to start the station process
	if (argc != 4) 
	{
		printf("\n INVALID format: Enter as: ./SP <server name> <port> <station number>\n");
		exit(0);
	}
	
	//open file and write output to file.
    output_file = fopen("SP_OUTPUT.txt" , "w");
	
	if(output_file == NULL) 
	{
		perror("Error opening output file");
		return(-1);
    }
	
	//hostname stores the host address.
	char * hostname = argv[1];
	
	//portno stores the port number given by the user.
	portno = atoi(argv[2]);
	
	//station number entered by the user 
	stationNo = atoi(argv[3]);
	
	//open the input file based on the station number
    if(stationNo == 1){    
           input_file  = fopen("station_process1.txt" , "r"); 
	}		 
     else if(stationNo == 2){
           input_file  = fopen("station_process2.txt" , "r");   
	 }	          
     else if(stationNo == 3){
           input_file  = fopen("station_process3.txt" , "r");    
	 }
     else if(stationNo == 4){
           input_file  = fopen("station_process4.txt" , "r");    
	 }
     else if(stationNo == 5){
           input_file  = fopen("station_process5.txt" , "r");    
     }
     else if(stationNo == 6){
           input_file  = fopen("station_process6.txt" , "r");    
	 }
     else if(stationNo == 7){
           input_file  = fopen("station_process7.txt" , "r");    
	 }
     else if(stationNo == 8){
           input_file  = fopen("station_process8.txt" , "r");    
	 }
    else if(stationNo == 9){
           input_file  = fopen("station_process9.txt" , "r");    
    }
     else if(stationNo == 10){                    
           input_file  = fopen("station_process10.txt" , "r");           
    }
	
	//check if input file is opened without any errors.
    if(input_file == NULL) 
	{
		perror("Error opening the file");
		return(-1);
    }
	
	//creating client socket descriptor using TCP/IP
	if((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		HandleErrors("Error opening client socket");
	 
	
	//sets all the values to zero.
	bzero(&servaddr, sizeof(servaddr));
	
	//Fill in the server address
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(portno);
	
	
	//Connecting to server
	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
	{
		
		HandleErrors("ERROR in Connecting");
    }
	 
	
	
	FD_ZERO(&rset);
	
	for(;;)
	{
		FD_SET(fileno(input_file), &rset);    
		FD_SET(sockfd, &rset);                
		
		MAXSIZEfdp1 = sockfd + 1;
		
		nready = select(MAXSIZEfdp1 + 1, &rset, NULL, NULL, NULL);
		
		if(FD_ISSET(fileno(input_file), &rset)) 
		{
			bzero(sim_input,100);
			if(feof(input_file))
				return -1;
			if(fgets(sim_input,100,input_file) != NULL)
			{
				ProcessRequests(sim_input);
			}
		}
		
		if(FD_ISSET(sockfd, &rset))
		{
			bzero(server_reply, MAXSIZE);
		
			//read reply from server using socket descriptor.
			if ((read(sockfd, server_reply, MAXSIZE)) < 0)
			{
				HandleErrors("ERROR reading from socket");
			}
			
			frameNos++;
			DataFrame(server_reply);
		}
		
	}
	 /* close the socket */
     close(sockfd);
	/*close the both input file and output file*/
	fclose(input_file);
	fclose(output_file);
	return 0;
}



