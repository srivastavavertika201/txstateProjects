#include<iostream>
#include<iomanip>
#define SIZE 5
using namespace std;

enum Day {Monday,Tuesday,Wednessday,Thursday,Friday};

int main(){
	double sales[SIZE];
	double total =0.0;
	int index;
	
	for(index = Monday; index<Friday; index++){
		cout << "Enter Sale For " << index <<" day : ";
		cout <<'\n';
		cin >> sales[index];
		cout <<'\n';
	}
	cout << "Calculate total Sale of a week ";
	for(index = Monday;index < Friday; index ++){
		total = total + sales[index];
	}
cout <<'\n';
	cout << fixed << showpoint << setprecision(2);
	cout <<"Total Sale is: $" << total;
}
