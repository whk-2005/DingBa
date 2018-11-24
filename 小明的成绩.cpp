#include<iostream>
using namespace std;
int main()
{
	int a[5];
	for(int i=0;i<4;i++)
	{
		cin>>a[i];
		if(a[i]>=90&&a[i]<=100)
		{
			cout<<'A'<<" ";
		}
		else
		{
			if(a[i]>=80&&a[i]<90)
			{
				cout<<'B'<<" ";
			}
			else
			{
				if(a[i]>=70&&a[i]<80)
				{
					cout<<'C'<<" ";
				}
				else
				{
					if(a[i]>=60&&a[i]<70)
					{
						cout<<'D'<<" ";
					}
					else
					{
						cout<<'E'<<" ";
					}
				}
			}
		}
	}
	int i=4;
	cin>>a[i];
	if(a[i]>=90&&a[i]<=100)
	{
		cout<<'A';
	}
	else
	{
		if(a[i]>=80&&a[i]<90)
		{
			cout<<'B';
		}
		else
		{
			if(a[i]>=70&&a[i]<80)
			{
				cout<<'C';
			}
			else
			{
				if(a[i]>=60&&a[i]<70)
				{
					cout<<'D';
				}
				else
				{
					cout<<'E';
				}
			}
		}
	}
	return 0;	
 } 
