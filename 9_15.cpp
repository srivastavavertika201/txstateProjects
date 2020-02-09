#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#define nullptr

using namespace std;

int *getRandomNumbers(int);

int main(){
	int *numbers= nullptr;
	
	numbers = getRandomNumbers(5);
	
	for(int i=0;i<5;i++){
		cout << "Numbers are : " << *numbers << " ";
		numbers++;
	}
	return 0;
}

int *getRandomNumbers(int n){
	int *arr = nullptr;
	if(n<=0){
		return nullptr;
	}
	arr = new int[n];
	srand(time(0));
	for(int i=0;i<n;i++){
		arr[i]=rand();
	}
	return arr;
}
