#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int size=12;
	int id = 9;
	bool swap;
	int temp;
	string nameArr[size]={ "John", "Jack", "Nick", "Keil", "Neil",
				"Jonathan", "Alen", "Sam", "Krystal", "Andrew", "Elizabeth",
				"David"};
	string email[size] = { "John123@gmail.com", "Jack@yahoo.com",
				"Nick321@outlook.com", "Keil_S135@gmail.com",
				"Neil655@gmail.com", "Jonathan_H@gmail.com",
				"Alen18765@gmail.com", "Sam_sam@gmail.com",
				"Krystal342@gmail.com", "Andrew05@gmail.com",
				"Elizabeth65@gmail.com", "David12@gmail.com" };

	int idArr[size] = {7,2,3,8,9,1,4,13,12,56,76,44};
	cout<<'\n';
	cout << "The original unsorted array: " <<'\n';
	for(int i=0;i<size;i++){
		cout << idArr[i] << " ";
	}
	cout <<'\n';
	cout <<'\n';
	cout << "The new sorted array: " << '\n';
	for(int j=0;j<size;j++){
	swap=false;
	for(int i=0;i<size-j;i++){
		if(idArr[i+1]<idArr[i]){
			temp=idArr[i];
			idArr[i]=idArr[i+1];
			idArr[i+1]=temp;
			swap = true;
		}
	}
	if(swap==false){
		break;
	}
}
	for(int i=0;i<size;i++){
		cout << idArr[i] << " ";
	}
	
	cout<<'\n';
	cout<<'\n';
	for(int count=0;count<6;count++){
	int l=0;
	int u=size-1;
	int mid; 
	int position=-1;
	cout<<'\n';
	cout << "Enter id you want to search:" <<'\n';
	cin>> id;
	cout<<'\n';
	while(l<=u){
		mid = (l+u)/2;
		if(idArr[mid] == id){
			
			position=mid;
			break;
		}
		else if(id<idArr[mid]){
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
