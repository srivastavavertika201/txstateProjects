#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool openFileIn(fstream &,string);
void showContents(fstream &);

int main(){
	fstream openFile;
	if(openFileIn(openFile,"openFile.txt")){
		cout << "File opened Successfully";
		showContents(openFile);
		openFile.close();
		cout<< "Done. ";
	}
	else{
		cout <<"File Open Error:: "<< endl;
	}
return 0;
}

bool openFileIn(fstream &oFile,string name){
	oFile.open("name", ios::in);
	if(oFile.fail()){
		return false;
	}
	else
		return true;
}

void showContents(fstream &file){
	string line;
	while(file >> line){
		cout << line << endl;
	}
}
