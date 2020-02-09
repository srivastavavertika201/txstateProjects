//#include<iostream>
#include<stdio.h>

//using namespace std;
int main()
{
union{
short s;
char c[sizeof(short)];
}myunion;
myunion.s = 0x0102;
if(sizeof(short) == 2)
{
if(myunion.c[0] == 1 && myunion.c[1] == 2)
cout<<"big-endian"<<endl;
else if(myunion.c[0] == 2 && myunion.c[1] == 1)
cout<<"little-endian"<<endl;
else
cout<<"Invalid"<<endl;
}
else
{
cout<<"size = "<<sizeof(short)<<"\n";
}
return 0;
}
