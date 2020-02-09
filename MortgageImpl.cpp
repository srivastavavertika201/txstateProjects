#include<bits/stdc++.h>
#include"Mortgage.h"

using namespace std;

void displayMenu();

int main(){
	Mortgage mortgage;
	char choice;
	double amnt;
	double rate;
	int years;
	//cout << fixed << showpoint << setprecision(2);
	
	do{
		displayMenu();
		cin >> choice;
		while(toupper(choice)<'A' || toupper(choice)>'E'){
			cout << "Invalid Selection: Please choose valid choice from A to E.";
			cin >> choice;
		}
		switch(choice){
			case 'a':
				case 'A': cout<< "Please Enter the Loan Amount in $ :" << endl;
							cin >> amnt;
							mortgage.setLoanAmnt(amnt);							
							cout << "Please Enter interest Rate: " << endl;
							cin >> rate;
							mortgage.setIntRate(rate);
							cout << "Please enter no. of years for loan." << endl;
							cin >> years;
							mortgage.setYears(years);
							cout << "Mortgage Term:" << mortgage.calcTerm()<<endl;
							cout << "Mortgage Payment:"<< mortgage.calcPayment();														
				break;
			case 'b':
				case 'B': cout<< "Interest Rate is:" <<mortgage.getIntRate()*100;
				break;
				case 'c':
				case 'C': cout<<"Loan Amount: " << mortgage.getLoanAmnt();
				break;
				case 'd':
				case 'D': cout<<"Total paid amount during loan period:" <<mortgage.getTotalPay();
				break;
		}
	}while(toupper(choice)!='E');
	return 0;
}

void displayMenu(){
	cout <<endl;
	cout <<"\n				Menu \n";
	cout << "***********************************************\n";
	cout << "A) Display the monthly payment based on Loan amount, interest rate and terms. \n";
	cout << "B) Display monthly interest.\n";
	cout << "C) Display monthly principle payment. \n";
	cout << "D) Display total payment during the loan period.";
	cout << "E) Exit. \n";
	cout << "Enter your choice : \n";
}


