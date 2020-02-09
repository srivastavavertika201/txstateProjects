#include<iostream>
#include<fstream>
#include <ctime>
#include <cstdlib>
#define length 20

using namespace std;

int saleProd[length];
struct product{
	int prodId;
	float prodPrice;
	int quant_sold;
	int prodIdOutput;
	float prodPriceOutput;
	int quant_soldOutput;
};
product obj[length];
void salesFun(struct product prod_units[], struct product prod_quantity[]) 
{ 
	cout << "\n";
	int salePerId=0;
	int unitsold = 0;
	cout<< "Id" << '\t' << "Price" << '\t' << "Quantity" << '\t' <<"Total Sales";
	cout<< "\n";
	cout <<"***********************************************************";
	cout<< "\n";
	for(int id=0;id<length;id++){
		cout << obj[id].prodId << '\t' << "  " <<obj[id].prodPrice <<'\t' << "  " << obj[id].quant_sold << '\t' << "       " << (obj[id].prodPrice*obj[id].quant_sold);
		cout << "\n";
	}
	cout << "\n";
	for(int count = 0;count<length;count++){
		salePerId = salePerId + (obj[count].prodPrice*obj[count].quant_sold);
		unitsold = unitsold+obj[count].quant_sold;
	}
	cout << "\n";
	cout << "Total Unit Sold: ";
	cout << unitsold;
	cout << "\n";
	cout << "Total Sale of all items: ";
	cout << salePerId;
	cout <<"\n";
	cout <<"***********************************************************";
}
int *bubble(int arr[], int n)
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
	int j =0,k=0,l=0,m=0,n=0;
	int * total_sold_units = &m;
	int * total_sale = &n;
    //ofstream outfile;           
    //outfile.open("prodFile.txt");
	cout << "Enter details of " << length <" products: \n";
	for(int i=0;i<length;i++){
		cout << '\n';
		cout<<"ProductId for item "<< (i+1) <<'\n';
		cin >> obj[i].prodId;
		cout <<'\n';
		cout << "Price for item "<< (i+1) <<'\n';
		cin >> obj[i].prodPrice;
		cout <<'\n';
		cout << "Quantities of item "<< (i+1) << " sold " <<'\n';
		cin >> obj[i].quant_sold;
		cout <<"\n";
	}
	//Product obj;
	fstream file;
	cout <<"\n";
	cout << "Writing File....!! \n";
	file.open("ProdFile.txt", ios::out);
	file<< "Product Id : \n";
	for(int pId=0;pId<length;pId++){
		file<<obj[pId].prodId;
		file <<"\n";
	}
	file <<"\n";
	file<< "Product Price : \n";
	for(int pPr=0;pPr<length;pPr++){
		file<<obj[pPr].prodId;
		file <<"\n";
	}
	file <<"\n";
	file<< "Product Quantity Sold in sequence to product Id: \n";
	for(int pQ=0;pQ<length;pQ++){
		file<<obj[pQ].prodId;
		file <<"\n";
	}	
	cout << "\n";
	//cout<< file.close() <<"File Closed Successfully!!";
	cout << "\n";
		ifstream infile("prodFile.txt");
		for (int i = 0; i < length * 3; i++)
		{
			if( !(i%3)){
				infile >> obj[j].prodIdOutput; 
				j++;
			}
			else if(!(i%2)){
				infile >> obj[k].quant_soldOutput;
				k++;
			}
			else{
				infile >> obj[l].prodPriceOutput;
				l++;
			}
		}
		salesFun(obj,obj); 
		for (int i=0; i<length; i++){
			m += obj[i].quant_soldOutput;
			n += saleProd[i];
		}
		bubble(saleProd,length);
		int r=0;
		//cout << "ID      UNIT PRICE    QUANTITY SOLD    TOTAL SALES" << endl <<"**************************************************"<<endl;
		while(r<20){
		for (int i=0; i < length; i++)
		{  

		    if( saleProd[r] == (obj[i].prodPrice * obj[i].quant_sold) ) {
			cout << obj[i].prodId << "\t";
			cout <<"$"<< obj[i].prodPrice << "\t\t";
			cout << obj[i].quant_sold << "\t\t";
			cout <<"$" << saleProd[r]  <<endl;

			r++;
        }}
		}
		cout << endl <<"Total sold Units : " <<*total_sold_units  << endl;
		cout <<"Total Sale:$"<<*total_sale;

   return 0;
}
