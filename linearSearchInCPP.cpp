#include<iostream>

using namespace std;

int searchList(const int[],int,int);
const int SIZE =5;

int main(){
	int test[SIZE] ={20,40,60,100,120};
	int results;
	results = searchList(test,SIZE,100);
	if(results==-1){
		cout << "Yod do not receive 100 in any test." << '\n';
	}
	else{
		cout << "You received 100 marks in test # " << results+1 << '\n';
	}
	return 0;
}

int searchList(const int test[],int size,int n){
	bool found = false;
	int position =-1;
	int index = 0;
	while(index < size && !found){
		if(test[index]==n){
			found=true;
			position =index;
		}
	index++;
	}
	return position;
}
