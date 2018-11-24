#include<bits/stdc++.h>
using namespace std;
int pd(int a)
{
	while(a%2==0)
	{
		a=a/2;
	}
	while(a%3==0)
	{
		a=a/3;
	}
	while(a%5==0)
	{
		a=a/5;
	}
	while(a%7==0)
	{
		a=a/7;
	}
	if(a==1)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}
int main()
{
	int c;
	cin>>c;
	for(int i=0;i<c;i++)
	{
		int a;
		cin>>a;
		pd(a);
	}
	return 0;
}
