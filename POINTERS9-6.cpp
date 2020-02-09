#include<iostream>
using namespace std;

int main(){
	const int SIZE =5;
	int numbers[SIZE];
	int count;
	
	cout << "Enter " << SIZE << " numbers: ";
	for(count=0;count<SIZE;count++)
		cin >> *(numbers + count);
		
		cout << "Here are the numbers you entered: ";
		for(count =0;count<SIZE;count++){
			cout << (*numbers + count) << " ";
		}
		cout << '\n';
		return 0;
}
