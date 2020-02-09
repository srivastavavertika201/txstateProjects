#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct StudentInfo{
	string name;
	int idNum;
	int creditHours;
	double gpa;
};

void getData(StudentInfo *);

int main(){
	StudentInfo student;
	getData(&student);
	cout<<'\n';
	cout<< fixed << showpoint << setprecision(2);
	cout << "Student details is as below: " << '\n';
	cout << "Student Name: " << student.name << '\n';
	cout<<'\n';
	cout<<"Student ID: "<< student.idNum <<'\n';
	cout<<'\n';
	cout<<"Student Credit Hours: " << student.creditHours <<'\n';
	cout<<'\n';
	cout<<"Student gpa : " << student.gpa <<'\n';
	cout<<'\n';
return 0;
}

void getData(StudentInfo *stu){
	cout << "Enter student name: " <<'\n';
	cin.ignore();
	getline(cin, stu->name);
	cout<<'\n';
	cout << "Enter student id: " <<'\n';
	cin >> stu->idNum;
	cout<<'\n';
	cout << "Enter student cfreditHours: " <<'\n';
	cin >> stu->creditHours;
	cout<<'\n';
	cout << "Enter student gpa: " <<'\n';
	cin >> stu->gpa;
	cout<<'\n';
}
