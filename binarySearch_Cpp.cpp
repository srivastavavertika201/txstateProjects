#include<iostream>

using namespace std;

int binarySearch(const int [],int, int);
const int SIZE = 20;

int main(){
	int empId;
	int result =-1;
	int empList[SIZE] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; 
	cout << "Enter employee Id you want to search : " <<'\n';
	cin >> empId;
	result = binarySearch(empList,SIZE,empId);
	if(result ==-1){
		cout << "Employee id does not exist in the list";
	}
	else{
		cout << "Employee id is found at location : " << result;
	}
	return 0;
}

int binarySearch(const int test[],int size,int n){
	bool found =false;
	int position=-1;	
	int first =0;
	int last = size-1;
	int mid;
	while(first <=last && !found){
	mid = (first+last)/2;
	if(test[mid]==n){
		found =true;
		position =mid;
	}
	else if(test[mid]<n){
		first = mid+1;
	}
	else{
		last =mid-1;
	}
	}	
	return position;
	}
