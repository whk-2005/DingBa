#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char c[31];
		//gets(c);
		scanf("%s",c);
		for(int j=0;c[j]!='\0';j++)
		{
			if(c[j]>='A'&&c[j]<='Z')
			{
				c[j]=c[j]+'a'-'A';
			}
			
		}
		//printf("%s\n",c);
		puts(c);
	}
	return 0;
}
