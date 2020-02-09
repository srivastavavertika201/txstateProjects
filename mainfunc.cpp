#include<bits/stdc++.h>
#include"classspecify.h"
using namespace std;
void student::getscores()
{
	ifstream f;
	f.open("testscore.txt");
	if(!f)
	{
		cout<<"FILE CAN'T BE OPEN";
	}
	else
	{
		while(!f.eof())
		{
			int sum=0;
			f>>id;
			float aveg;
			for(int i=0;i<10;i++)
			{
				f>>scores[i];
				sum+=scores[i];
			}
			m[id]=scores;
			aveg=sum/(10.0);
			avg[id]=aveg;
		}
	}
	f.close();
}
void student::show()
{
	ifstream f;
	f.open("studentdata.txt");
	if(!f)
	{
		cout<<"ERROR IN OPENING FILE\n";
	}
	else
	{
		while(!f.eof())
		{
			string name;
			int id1;
			f>>id1;
			f>>name;
			if(m.find(id1)==m.end())
			{
				cout<<"Test scores of student with id: "<<id1<<" not found\n";
			}
			else
			{
				cout<<"ID: "<<id1;
				cout<<"\nNAME: "<<name;
				cout<<"\nAVERAGE: "<<avg[id1];
				cout<<"\nMARKS: ";
				for(int i=0;i<10;i++)
				{
					cout<<(m[id1])[i]<<" ";
				}cout<<'\n';
				cout<<'\n';
			}
		}
		f.close();
	}
}
int main()
{
	student s;
	s.getscores();
	s.show();
}
