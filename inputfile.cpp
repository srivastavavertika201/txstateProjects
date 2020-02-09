#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main()
{
	ofstream f;
	f.open("studentdata.txt");
	if(!f)
	{
		cout<<"ERROR IN OPENING FILE\n";
	}
	else
	{
		for(int i=0;i<16;i++)
		{
			string name;
			int id;
			cout<<"ENTER ID AND NAME OF STUDENT "<<i+1<<"\n";
			cin>>id>>name;
			f<<id<<" "<<name<<'\n';
		}
		f.close();
	}
	f.open("testscore.txt");
	if(!f)
	{
		cout<<"ERROR IN OPENING FILE\n";
	}
	else
	{
		for(int i=0;i<16;i++)
		{
			vector<int> scores(10);
			int id;
			cout<<"ENTER ID OF STUDENT "<<i+1<<"\n";
			cin>>id;
			f<<id<<" ";
			cout<<"ENTER MARKS OF STUDENT IN 10 SUBJECTS\n";
			for(int j=0;j<10;j++)
			{
				cin>>scores[j];
				f<<scores[j];
				if(j!=9)
				{
					f<<" ";
				}
				else
				{
					f<<'\n';
				}
			}
		}
		f.close();
	}
}
