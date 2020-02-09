#include<iostream>
#include<fstream>
#define length 20

using namespace std;

struct Product{
		int prodId;
		double prodPrice;
		int quantitySold;
		double totalSale;
		int totalUnitSold;
	};
	
int *bubbleSort(int arr[], int n)
{

int x,y,i,j;

  				 for (i = 0; i < n-1; i++)
  				 {
     			  for (j = 0; j < n-i-1; j++)
   					  {
       				 if (arr[j] > arr[j+1])
      			  {
          			 int temp = arr[j];
    	  			 arr[j]  = arr[j+1] ;
    	   			 arr[j+1]= temp;
				 }
    			 }
 				 }
 	return arr;
}	
	obj[length];
int main(){
	
	ofstream file;
	file.open("ProdFile.txt", ofstream :: out);
	file<< "Product Id : \n";
	for(int pId=0;pId<num;pId++){
		file<<prodId[pId];
		file <<"\n";
	}
	file <<"\n";
	file<< "Product Price : \n";
	for(int pPr=0;pPr<num;pPr++){
		file<<prodPrice[pPr];
		file <<"\n";
	}
	file <<"\n";
	file<< "Product Quantity Sold in sequence to product Id: \n";
	for(int pQ=0;pQ<num;pQ++){
		file<<quant[pQ];
		file <<"\n";
	}	
	cout << "\n";
	cout<< file.close() <<"File Closed Successfully!!";
	cout << "\n";
//Open file to read
	ifstream fileRead; 
	string lineCount, line, value;
	myFile.open("ProdFile.txt", ifstream :: binary); // Will be used to open the file
	if (! fileRead)	
	{
		cout<< "File does not exist\n";
	}
	cout<< << "product details inside text file\n";
	Product* prodArr = new Product[count];
	Product* prodArr = arr;
	while(getline(fileRead, line, ';')) // Insert product id, unit cost and product sale into their respective arrays. 
	{
		line_iter = 1;
		stringstream buffer_line;
		buffer_line << line;
		while(getline(buffer_line, value, ','))
		{
			if (line_iter % 2 == 0)
			{
				stringstream value_float;
				value_float << value;
				value_float >> pCost;
				arr[iterator].prodCost = pCost;
			}
			else if (line_iter % 3 == 0)
			{
				stringstream value_int_pn;
				value_int_pn << value;
				value_int_pn >> pSold;
				arr[iterator].prodSold = pSold;
			}
			else 
			{
				stringstream value_int_pid;
				value_int_pid << value;
				value_int_pid >> pId;
				arr[iterator].prodId = pId;
			}
			line_iter++;
		}
		iterator++;
	}
	fileRead.close(); 
}

