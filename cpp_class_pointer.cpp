#include<iostream>

using namespace std;

int main()
{
	int * ptr;
	int **pt;
	int x =6;
	cout << &x << endl;
	ptr=&x;
	cout << ptr <<endl;
	pt=&ptr;
	cout << pt;
}
