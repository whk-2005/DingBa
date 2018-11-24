#include<iostream>
using namespace std;
int main() 
{
	/*int n;
	cin>>n;*/
	int n,sum;
	while(cin>>n)
	{
		sum=0;
		int a[n];
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			sum+=a[j];
		}
		cout<<sum<<endl;
	}
	return 0;
}
