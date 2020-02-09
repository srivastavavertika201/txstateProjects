#include<bits/stdc++.h>
#include<fstream>
using namespace std;
class student
{
	int id;
	map<int,string> name;
	map<int,float> avg;
	vector<int> scores;
	map<int,vector<int> > m;
	public:
		student()
		{
			scores.resize(10);
		}
		void getscores();
		void show();
};
