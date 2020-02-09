#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int size=6;
	int id = 9;
	bool swap;
	int temp;
	int arr[size] = {7,2,3,8,9,1};
	cout<<'\n';
	cout << "The original unsorted array: " <<'\n';
	for(int i=0;i<size;i++){
		cout << arr[i] << " ";
	}
	cout << "The new sorted array: " << '\n';
	for(int j=0;j<size;j++){
	swap=false;
	for(int i=0;i<size-j;i++){
		if(arr[i+1]<arr[i]){
			temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
			swap = true;
		}
	}
	if(swap==false){
		break;
	}
}
	for(int i=0;i<size;i++){
		cout << arr[i] << " ";
	}
	
	cout<<'\n';
	cout<<'\n';
	for(int count=0;count<6;count++){
	int l=0;
	int u=size-1;
	int mid; 
	int position=-1;
	cout<<'\n';
	cout << "Enter element you want to search:" <<'\n';
	cin>> id;
	cout<<'\n';
	while(l<=u){
		mid = (l+u)/2;
		if(arr[mid] == id){
			
			position=mid;
			break;
		}
		else if(id<arr[mid]){
			u=mid-1;			
		}
		else{
			l=mid+1;
		}
	}
	cout<<'\n'; 
	cout << "The entered id is found at index position:" << '\n';
	cout << position <<'\n';	
}
	return 0;
}
