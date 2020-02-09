#include <iostream>
using namespace std;

void displayValues(const int *, int);

int main()
{
 const int SIZE = 6;

 const int array1[SIZE] = { 1, 2, 3, 4, 5, 6 };

 int array2[SIZE] = { 2, 4, 6, 8, 10, 12 };

 displayValues(array1, SIZE);

 displayValues(array2, SIZE);
 return 0;
 }
 void displayValues(const int *numbers, int size)
 {
 for (int count = 0; count < size; count++)
 {
 cout <<"The address of pointer variable is:  "<< numbers <<'\n';
 cout <<"Variable of an array using indirection operator : " << *(numbers + count) << '\n';
 cout <<"PointerVariable : " <<  numbers[count] <<'\n';
 numbers++;
 }
 cout << endl;
 }
