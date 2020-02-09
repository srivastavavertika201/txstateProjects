#include<iostream>
#include<cstdlib>
#include<string>
#include<math.h>
#include"Mortgage.h"

using namespace std;

void Mortgage::setLoanAmnt(double amnt){
	loanAmnt =amnt;
}
void Mortgage::setIntRate(double rate){
	intRate = rate;
}
void Mortgage::setYears(int years){
	years=years;
}
double Mortgage::getLoanAmnt(){
	return loanAmnt;
}
double Mortgage::getIntRate(){
	return intRate;
}
int Mortgage::getYears(){
	return years;
}
double Mortgage::calcTerm(){
	double term;
	term = pow((1+(intRate/12)),(12*years));
	return term;
}
double Mortgage::calcPayment(){
	double payment;
	payment = ((loanAmnt*(intRate/12)*term)/(term - 1));
	return payment;
}
void Mortgage::dispDetails(){
		
}
	

