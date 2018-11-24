#include<bits/stdc++.h>
using namespace std;
long long pd(long long a){
	long long a1=0,b=0,c=0,d=0; 
	while(a%2==0){
		a/=2;
		a1++;
	}
	while(a%3==0){
		a/=3;
		b++;
	}
	while(a%5==0){
		a/=5;
		c++;
	} 
	while(a%7==0){
		a/=7;
		d++;
	}
	long long s=(a1+1)*(b+1)*(c+1)*(d+1);
	return s;
}
int main(){
	long long n;
	while(cin>>n&&n!=0){
		long long k=pd(n);
		cout<<k<<endl;
	}
	return 0;
}
