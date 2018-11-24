#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a==0&&b==0)
			break;
		if(a<b)
		{
			int t;
			t=a;
			a=b;
			b=t;
			cout<<a-b<<endl;
		}
		else
		{
			cout<<a-b<<endl;
		}
	}
	return 0;
 } 
