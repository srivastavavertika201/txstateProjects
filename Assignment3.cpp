#include<iostream>
using namespace std;

int main(){
	int x=25;
	short y = 2;
	bool b=true;
	char c ='a';
	long l = 12345667;
	string s="This is Assignment 3";
	float f = 12.21;
	double d=13.3233;
	long double ld = 1233.8787676756;
	int n;
	const int SIZE = 5;
	int arr[SIZE]={7,2,3,8,9};
	
	int *ptr;
	short int *sptr;
	bool *bptr;
	char *cptr;
	long *lptr;
	string *stptr;
	float *fptr;
	double *dptr;
	long double *ldptr ;	
	
	ptr = &x;
	cout << "The value of entered integer using pointer is: " << *ptr <<'\n';
	cout << "The address of entered integer using pointer is: " << ptr <<'\n';
	cout << "The size of entered integer using pointer is : " << sizeof(*ptr) << " bytes" <<'\n';
	cout <<'\n';
	sptr = &y;
	cout << "The value of entered short integer using pointer is: " << *sptr <<'\n';
	cout << "The address of entered short integer using pointer is: " << sptr <<'\n';
	cout << "The size of entered short integer using pointer is: " << sizeof(*sptr) << " bytes" <<'\n';
	cout <<'\n';
	bptr = &b;
	cout << "The value of entered boolean using pointer is: " << *bptr <<'\n';
	cout << "The address of entered boolean using pointer is: " << bptr <<'\n';
	cout << "The size of entered boolean using pointer is: " << sizeof(*bptr) << " bytes" <<'\n';
	cout <<'\n';
	cptr = &c;
	cout << "The value of entered char element using pointer is: " << *cptr <<'\n';
	cout << "The address of entered char element using pointer is: " << (void*)cptr <<'\n';
	cout << "The size of entered char element using pointer is: " << sizeof(*cptr) << " byte" <<'\n';
	cout <<'\n';
	lptr = &l;
	cout << "The value of entered long integer using pointer is: " << *lptr <<'\n';
	cout << "The address of entered long integer using pointer is: " << lptr <<'\n';
	cout << "The size of entered long integer using pointer is: " << sizeof(*lptr) << " bytes" <<'\n';
	cout <<'\n';
	stptr = &s;
	cout << "The value of entered string using pointer is: " << *stptr <<'\n';
	cout << "The address of entered string using pointer is: " << stptr <<'\n';
	cout << "The size of entered string using pointer is: " << sizeof(*stptr) << " byte" <<'\n';
	cout <<'\n';
	fptr = &f;
	cout << "The value of entered float using pointer is: " << *fptr <<'\n';
	cout << "The address of entered float using pointer is: " << fptr <<'\n';
	cout << "The size of entered float using pointer is: " << sizeof(*fptr) << " bytes" <<'\n';
	cout <<'\n';
	dptr = &d;
	cout << "The value of entered double using pointer is: " << *dptr <<'\n';
	cout << "The address of entered double using pointer is: " << dptr <<'\n';
	cout << "The size of entered double using pointer is: " << sizeof(*dptr) << " bytes" <<'\n';
	cout <<'\n';
	ldptr = &ld;
	cout << "The value of entered long double using pointer is: " << *ldptr <<'\n';
	cout << "The address of entered long double using pointer is: " << ldptr <<'\n';
	cout << "The size of entered long double using pointer is: " << sizeof(*ldptr) << " bytes" <<'\n';
	cout <<'\n';
	ptr = arr;
	cout << "First element of array is: " ;
	cout << *ptr <<'\n';	
	cout << "Elements of an array using pointer is :  ";
	for(int i=0;i<SIZE;i++){
	cout << *ptr << " " <<'\n';
	cout << ptr;
	ptr++;
	}	
	cout <<'\n';
	cout <<" Size of an array using pointer is: "<< sizeof(arr);
	cout <<'\n';
	cout <<" Address of an array using pointer is: "<< ptr;
	return 0;
}
