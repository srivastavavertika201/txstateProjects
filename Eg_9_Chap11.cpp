#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

union Employee{
	int hours;
	double sales;
};

int main(){
	Employee emp;
	char payType;
	float payRate;
	float grossPay;
	
	cout << "Enter payType H for hourly based and C for Commission Based: "<< '\n';
	cout <<'\n';
	cin >> payType;
	cout <<'\n';
	if(payType=='H'||payType=='h'){
		cout << "What is the payRate of employee? " << '\n';
		cin >> payRate;
		cout << "How many hours does he worked?? " << '\n';
		cin >> emp.hours;
		grossPay = payRate * emp.hours;
		cout << "Gross Pay is $: " << grossPay;
	}
	else if(payType=='C'|| payType =='c'){
		cout << "What is the sales of employee? " <<'\n';
		cin >> emp.sales;
		grossPay = emp.sales *0.10;
		cout <<'\n';
		cout << "Gross Pay: $ " << grossPay;
	}
	else {
		cout << payType << " is not a valid option.";
	}
return 0;
}
