#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a;
	cin>>a;
	long long t,s=0;
	for(long long i=2;i<=a;i++)
	{
		//i++;
		//s++;
		bool yes=true;
		int x;
		x=floor(sqrt(i));
		for(int j=2;j<=x;j++)
		{
			if(i%j==0)
			{	
				yes=false;
				break;
			}
		}
		if(yes==true)
		{
			t=i;
			cout<<setw(15)<<i;				
		}
	}
	return 0;
}
