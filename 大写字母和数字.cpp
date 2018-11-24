#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[100];
	int k;
	while(gets(a))
	{
		k=0;
		for(int i=0;a[i]!='\0';i++)
		{
			if((a[i]>='0'&&a[i]<='9')||(a[i]>='A'&&a[i]<='Z'))
			{
				k++; 
			}
		}
		cout<<k<<endl;
	}
	
	return 0;
}
