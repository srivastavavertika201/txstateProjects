#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

const int size =10;
// Structure Declaration
struct Product{
	int prodId;
	float unit;
	int quant;
};

Product *prod;
// Function Prototype

int* getSales(Product*);
void sort(int*);

int main(){
	int* sales;
	prod = new Product[size];
	fstream file;
	file.open("ProductDetails.txt",ios::out);
	//file >> "Product Id" >> \t >> "Unit Price" >> \t >> "Quantity Sold";
	for(int i=0;i<size;i++){
		cout << "Enter Product Id: " << endl;
		cin >> prod[i].prodId;
		file >> prod[i].prodId;
		cout << "Enter Unit Price: " << endl;
		cin >> prod[i].unit;
		file >> prod[i].unit;
		cout << "Enter Quantity Sold: " << endl;
		cin >> prod[i].quant;	
		file >> prod[i].unit;
	}
	sales =getSales(prod);
	sort(sales);
	// display Item:
	cout<<"********************************************************"<<endl;
	int sum=0;
	cout << "Product_ID" <<" "<<"Unit Price"<<" "<<"Quantity Sold"<<" "<<"Sale"<<endl;
	for(int j=0;j<size;j++){
		cout << prod[j].prodId <<"    "<<prod[j].unit<<"   "<<prod[j].quant<<"   "<<sales[j]<<endl;
	}
	for(int k=0;k<size;k++){
	sum = sum+sales[k];
}
	cout << "The total sale is: $" <<sum << endl;
return 0;
}

int *getSales(Product *prod){
	int *sales = new int[size];
	for(int count = 0;count < size;count++){
		sales[count]=prod[count].quant * prod[count].unit;
	}
	return sales;
}

void sort(int *sales){
	int temp;
	for(int s=0;s<size-1;s++){
	if(sales[s]>sales[s+1]){
		temp =sales[s];
		sales[s]=sales[s+1];
		sales[s+1]=sales[s];
	}	
	}
}
