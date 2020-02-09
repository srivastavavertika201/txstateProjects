#include<iostream>
#include<fstream>
using namespace std;

int main(){
	fstream File;
	cout << "Opening a File.......\n";
	File.open("Productfile.txt", ios::out);	
	cout << "Write Product Name..";
	File << "Books \n";
	File << "Pencil \n";
	File << "Glass \n";
	File << "Ink \n";
	File << "Apple \n";
	File << "Pineapple \n";
	File << "Orange \n";
	File << "Mobile \n";
	File << "Charger \n";
	File << "Dress \n";
	File << "** \n";
	cout << "Write Product Price..";
	File << "$23 \n";
	File << "$10 \n";
	File << "$12 \n";
	File << "$8 \n";
	File << "$7 \n";
	File << "$9 \n";
	File << "$7 \n";
	File << "$900 \n";
	File << "$65 \n";
	File << "$150 \n";
	File << "** \n";
	cout << "Write Product Quantity..";
	File << "1 \n";
	File << "2 \n";
	File << "3 \n";
	File << "1 \n";
	File << "2 \n";
	File << "2 \n";
	File << "3 \n";
	File << "1 \n";
	File << "1 \n";
	File << "5 \n";
	File << "** \n";
	File.close();
	cout << "Done";
	return 0;	
	
}

