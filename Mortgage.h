#include<bits/stdc++.h>
using namespace std;

double power(double x,int y)
{
	return pow(x,y);
}
class Mortgage
{
	private:
		double loanAmnt;
		double intRate;
		int years;
		double payment;
		double term;
	public:	
	void setLoanAmnt(double);
	void setIntRate(double);
	void setYears(int);
	double getLoanAmnt();
	double getIntRate();
	int getYears();
	double calcTerm();
	double calcPayment();
	double getTotalPay();
};

void Mortgage::setLoanAmnt(double amnt){
	loanAmnt =amnt;
}
void Mortgage::setIntRate(double rate){
	intRate = rate/100;
}
void Mortgage::setYears(int y){
	years=y;
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
	int y=years;
	double rate=intRate/12+1;
	term = power(rate,12*y);
	return term;
}
double Mortgage::calcPayment(){
//	if(term>=1){
	payment = ((loanAmnt*(intRate/12)*term)/(term - 1));
 	//payment = (loanAmnt * intRate) / (1 - pow(1+intRate,-term));
//		}
	return payment;
}
double Mortgage::getTotalPay(){
double total=0.0;
total=payment*years*12;
return total;		
	}
