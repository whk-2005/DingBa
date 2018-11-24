#include<bits/stdc++.h>
using namespace std;
int s[100];
int main()
{
	int a;
	cin>>a;
	float sum,pl,pj;
	for(int i=0;i<a;i++)
	{
		pl=0;
		sum=0;
		s[i]={0};
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
			sum+=s[i];
		}
		pj=sum/n;
		printf("%.2f ",pj);
		for(int i=0;i<n;i++)
		{
			if(pj-s[i]<=0)
				pl+=s[i]-pj;
			else
				pl+=pj-s[i];
		}
		printf("%.2f\n",pl);
	}
	return 0;
}
