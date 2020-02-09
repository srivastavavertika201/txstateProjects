#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
using namespace std;

int main(){
	string fileName;
	char ch;
	ifstream inFile;
	
	ofstream outFile("outFile.txt");
	
	cout << "Enter filename: ";
	cin >> fileName;
	inFile.open("ProdFile.txt",ios::in);
	if(inFile){
		inFile.get(ch);
		
		while(inFile){
			outFile.put(toupper(ch));
			inFile.get(ch);
		}
		inFile.close();
		outFile.close();
		cout << "File conversation done.";
	}
	else
		cout << "ERROR: could not open file." <<endl;
		
	return 0;
}
