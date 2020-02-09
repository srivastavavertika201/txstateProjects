#include<iostream>
#include<iomanip>
using namespace std;

void getSales(double *,int);
double totalSales(double *,int);

int main(){
	const int SIZE = 4;
	double sales[SIZE];
	getSales(sales,SIZE);
	cout << "Finding total sales: ";
	cout << fixed << showpoint << setprecision(2);
	cout << totalSales(sales, SIZE);
	return 0;
}

void getSales(double *sales, int size){
	cout << "Enter sale for all" << size << "itemss: ";
	for(int i=0;i<size;i++){
	cin >> sales[i];
	//sales++;
	}
}

double totalSales(double *sales,int size){
	double sum =0.0;
	for(int i=0;i<size;i++){
		sum+= *sales;
		sales++;
	}
	return sum;
}
