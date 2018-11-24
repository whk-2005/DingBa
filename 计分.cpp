#include<iostream>
#include<iomanip>
using namespace std;
float a[59];
int main()
{
	int c;
	cin>>c;
	for(int i=0;i<c;i++)
	{
		int n,k=0;
		float sum=0,pj;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			sum+=a[j];
		}
		pj=sum/n;
		for(int j=0;j<n;j++)
		{
			if(a[j]>=pj)
				k++;
		}
		cout<<fixed<<setprecision(2)<<pj<<" ";
		cout<<k<<endl;
	}
	return 0;
 } 
