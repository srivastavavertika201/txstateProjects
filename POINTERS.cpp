#include<iostream>

using namespace std;

int main(){
	int x=25;
	double y=24.04;
	
	cout << "The address of x is : " << &x << '\n';
	cout << "The size of x is : " << sizeof(x) <<" bytes"<< '\n';
	cout << "The size of y is : " << sizeof(y) <<" bytes"<< '\n';
	cout << "The value of x is : " << x << '\n';
	
	return 0;
}

