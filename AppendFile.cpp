#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ofstream oFile;
	cout << "Open file to write data.\n";
	oFile.open("openFile.txt",ios::out);
	oFile << "John \n";
	oFile << "Monk \n";
	cout << "close file after writing data.\n";
	oFile.close();
	oFile.open("openFile.txt",ios::out| ios::app);
	cout << "Open again file to write data.\n";
	oFile<< "Tiger \n";
	oFile<<"William \n";
	cout << "close file after writing data.\n";
	oFile.close();
	cout << "Done\n";
	return 0;
	
}
