#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#define length 18 // intializng length = 18
using namespace std;

int sale[length]; // global array
struct product{
	//Dynamically allocating arrays
	int * id = new int[length];
	float * unit_price = new float[length];
	int * quantities_sold = new int[length];
	int * id_read = new int[length];
	float * unit_price_read = new float[length];
	int * quantities_sold_read = new int[length];

};
void sales(float *units, int *quantity )  // passing by address
{  // calculating the sales array
	for (int i=0; i< length; i++){
		sale[i] = units[i] * quantity[i];

	}
}

int *bubble(int arr[], int n)   // using bubble sort to sort sales and writing to array
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

int main ()
{
	int j =0,k=0,l=0,f=0,g=0;
	int * total_units_sold = &f; // using pointers to refer to variable
	int * total_sales_done = &g; // using pointers to refer to variable
	product obj;
    ofstream outfile;            //opening file to write
    outfile.open("afile.dat");
	srand(time(NULL) * 5 ) ;  // seeding random values with time
	for ( int i =0; i < length; i++)
	{
		obj.id[i] = i + 100;                  // filling arrays
		obj.unit_price[i] = (rand() % 50) ;
		obj.quantities_sold[i] = rand() % 50;
		outfile << obj.id[i] << "\t" << obj.quantities_sold[i] << "\t" << obj.unit_price[i] << endl;  // writting data to the files
		}
	outfile.close();   // closing the file
	ifstream infile("afile.dat"); // opening file to read
		for (int i = 0; i < length * 3; i++)
		{
			if( !(i%3)){
				infile >> obj.id_read[j]; // reading the file to arrays
				j++;
			}
			else if(!(i%2)){
				infile >> obj.quantities_sold_read[k];
				k++;
			}
			else{
				infile >> obj.unit_price_read[l];
				l++;
			}
		}
		sales(obj.unit_price_read,obj.quantities_sold_read);   // calculating total sales array
		for (int i=0; i<length; i++){
			f += obj.quantities_sold_read[i];
			g += sale[i];
		}
		bubble(sale,length); // sorting elements here.
		int r=0;
		cout << "ID      UNIT PRICE    QUANTITY SOLD    TOTAL SALES" << endl <<"--------------------------------------------------"<<endl;
		while(r<17){
		for (int i=0; i < length; i++)
		{   //printing values

		    if( sale[r] == (obj.unit_price_read[i] * obj.quantities_sold_read[i]) ) {
			cout << obj.id_read[i] << "\t";
			cout <<"$"<< obj.unit_price_read[i] << "\t\t";
			cout << obj.quantities_sold_read[i] << "\t\t";
			cout <<"$" << sale[r]  <<endl;

			r++;
        }}
		// if(r==18)break;
		}
		cout << endl <<"Total units sold           :" <<*total_units_sold  << endl;
		cout <<"Total Sale of all items    :$"<<*total_sales_done;

   return 0;
}
