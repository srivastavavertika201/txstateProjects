#include <iostream>
// #include<vector>
using namespace std;

int main(){
	int n=5;
	int target =1;
	int finalPos =-1;
	int arr[] = {1,2,3,4,1};
	for(int i=0;i<n;i++){
		if(arr[i] == target){
		finalPos = i+1;	
		}
	}
	return finalPos;
}


