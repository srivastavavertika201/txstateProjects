#include<iostream>
#include<iomanip>

using namespace std;

void showArray(const int [],int);
void sortArray(int [] ,int);

int main(){
	int values[6] = {7,2,3,8,9,1};
	cout << "The unsorted array is : " <<'\n';
	showArray(values,6);
	sortArray(values,6);
	cout <<'\n';
	cout<< "Sorted Array: " << '\n';
	showArray(values,6);
	
	return 0;
}

void showArray(const int arr[],int size){
	for(int i=0;i<size;i++){
		cout<< arr[i] << " ";
	}
}
void sortArray(int arr[],int size){
bool swap =false;
int temp;
int i=0;
for(int k=size-1;k>0;k--){
	for(i=0;i<size-1;i++){
		if(arr[i]>arr[i+1]){
			temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
			swap =true;
		}
	}
}
}  
