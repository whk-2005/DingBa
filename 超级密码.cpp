#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string a;
	getline(cin,a); 
	for(int i=0;i<n;i++)
	{
		string c;
		getline(cin,c);
		long long ds=0;
		//int x;
		for(int j=0;j<c.size();j++)
		{
			if(c[j]>='0'&&c[j]<='9')
			{
				//x=c[j]-'0';
				ds=ds*10+(c[j]-'0');
				//cout<<ds<<endl;
				//cout<<x<<endl;
			}
		}
		ds=ds*513;
		cout<<ds<<endl;
	}
	return 0;
}
