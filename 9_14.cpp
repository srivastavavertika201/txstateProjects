#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
	double *sales;
	double totalSales=0.0,averageSales=0.0;
	int numDays;
	cout <<"Enter number of days for which you want to calculate sales: ";
	cin >> numDays;
	
	sales = new double[numDays];
	for(int i=0;i<numDays;i++){
		cout << "Enter sale of " << i+1 << " day";
		cin >> sales[i];
	}
//total Sales
	for(int i=0;i<numDays;i++){
		totalSales+= sales[i];
	}
//average Sales
	averageSales = totalSales/numDays;
// Display	
	cout << "Total Sales : " << totalSales;
	cout <<'\n';
	cout <<'\n';
	cout << "Average : " << averageSales;
//Deallocate 
delete []sales;
sales = nullptr;
return 0;
}
