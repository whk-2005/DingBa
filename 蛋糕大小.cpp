//×¢Òâ¸¡µã 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		float a,b,c,d,e;
		float sp,ss;
		float sb; 
		cin>>a>>b>>c>>d>>e;
		sp=a*a;
		ss=b*c;
		sb=d*e/2;
		if(sp>ss&&sp>sb)
			cout<<"Perch"<<endl;
		if(ss>sp&&ss>sb)
			cout<<"Semon"<<endl;
		if(sb>ss&&sb>sp)
			cout<<"Belinda"<<endl;
	}
	return 0;
}
