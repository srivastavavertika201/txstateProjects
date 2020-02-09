#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

	struct Product{
		int prodId;
		double price;
		int quantity;

	};
	
int main(){
	
	int *prodId;
	double *prodPrice; 
	int *quant; 
	prodId = new int[num];
	prodPrice = new double[num];
	quant = new int[num];
	cout << "Enter details of " << num <" products: \n";
	for(int i=0;i<num;i++){
		cout << '\n';
		cout<<"ProductId for item "<< (i+1) <<'\n';
		cin >> prodId[i];
		cout <<'\n';
		cout << "Price for item "<< (i+1) <<'\n';
		cin >> prodPrice[i];
		cout <<'\n';
		cout << "Quantities of item "<< (i+1) << " sold " <<'\n';
		cin >> quant[i];
		cout <<"\n";
	}
	Product product;
	fstream file;
	cout <<"\n";
	cout << "Writing File....!! \n";
	file.open("ProdFile.txt", ios::out);
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
	// Print Array
	cout << "\n";
	int salePerId=0;
	int unitsold = 0;
	cout<< "Id" << '\t' << "Price" << '\t' << "Quantity" << '\t' <<"Total Sales";
	cout<< "\n";
	cout <<"***********************************************************";
	cout<< "\n";
	for(int id=0;id<num;id++){
		cout << prodId[id] << '\t' << "  " <<prodPrice[id] <<'\t' << "  " << quant[id] << '\t' << "       " << (prodPrice[id]*quant[id]);
		cout << "\n";
	}
	cout << "\n";
	for(int count = 0;count<num;count++){
		salePerId = salePerId + (prodPrice[count]*quant[count]);
		unitsold = unitsold+quant[count];
	}
	cout << "\n";
	cout << "Total Unit Sold: ";
	cout << unitsold;
	cout << "\n";
	cout << "Total Sale of all items: ";
	cout << salePerId;
	cout <<"\n";
	cout <<"***********************************************************";
	return 0;

}
