#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	int t;
	while(b!=0){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a,b,c,d,e,f,x,y;
		char t; 
		cin>>a>>t>>b>>c>>t>>d>>e>>t>>f;
		a=a*d*f;
		c=c*b*f;
		e=e*b*d;
		x=gcd(a,c);
		x=gcd(x,e);
		y=a/x+c/x+e/x;
		cout<<y<<endl;		
	}
	return 0;
}
//900,810,480
