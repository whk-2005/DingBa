#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string a;
	getline(cin,a);
	/*for(int i=0;i<n;i++)
	{
		
		char c[51],t;
		//gets(c);
		gets(c);
		for(int j=0;c[j]!='/0';j++)
		{
			t=c[j];
			c[j]=c[50-j];
			c[50-j]=c[j];
		}
		for(int j=1;c[j]!='/0';j++)
		{
			cout<<c[j];
		}
		cout<<endl;
	}*/
	for(int i=0;i<n;i++)
	{
		string c;
		
		getline(cin,c);
		for(int j=c.size()-1;j>=0;j--)
		{
			cout<<c[j];
		}
		cout<<endl;
	}
	return 0;
}
