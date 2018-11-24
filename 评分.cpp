#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;//ÓÐn¸öÆÀÎ¯ 
	while(cin>>n)
	{
		float a[100]={0};
		float zg=0,zd=100,sum=0,pj=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]>zg)
			{
				zg=a[i];
			}
			if(a[i]<zd)
			{
				zd=a[i];
			}
			sum+=a[i];
		}
		sum=sum-zg-zd;
		pj=sum/(n-2);
		cout<<fixed<<setprecision(2)<<pj<<endl;
	}
	return 0;
}
