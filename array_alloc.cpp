#include<iostream>
using namespace std;

int main(int argc, char** argv){
	int source;
	int dest;
	int k=0;
	cout<< "Enter source index from where elenment need to be copied" <<'\n';
	cin>> source;
	cout << "Enter destination index till elenment need to be copied"<<'\n';
	cin>>dest;
	int inArr[] = {1,2,3,4,5};
	cout << "The input array : "<<'\n';
	for(int in=0;in<5;in++){
		cout << inArr[in]<< " ";
	}
	int arr[] = {};
	for(int i=source;i<=dest;i++){
		arr[k]=inArr[i];
		k++;
	}
	cout << "The output array : "<<'\n';	
	for(int l=0;l<=dest;l++){
		cout<< arr[l] << " ";
	}
}
