#include<bits/stdc++.h>
using namespace std;
long long a[30]={0,0,1};
long long b[30]={1};
int main(){
	for(int i=3;i<30;i++){
		a[i]=(i-1)*(a[i-1]+a[i-2]);
	}
	int c;
	cin>>c;
	for(int i=0;i<c;i++){
		int n;
		cin>>n;
		long long sum=1;
		for(int j=2;j<=n;j++){
			sum*=j;
		}
		double temp=100.0*a[n]/sum;
		printf("%.2f%%\n",temp);
	}
	return 0;
} 
