#include<bits/stdc++.h>
using namespace std;
const int N=100008;
int f[N][12];
int dp[N][12];
int max3(int a,int b,int c){
	return max(max(a,b),max(b,c));
}
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		memset(f,0,sizeof(f));
		memset(dp,0,sizeof(dp));
		int x,T;
		int maxT=0;
		int m=0;
		while(n--){
			scanf("%d %d",&x,&T);
			f[T][x]++;
			maxT=max(maxT,T);
				
		}
		dp[1][4]=f[1][4];
		dp[1][5]=f[1][5];
		dp[1][6]=f[1][6];
		for(int i=2;i<=maxT;i++){
			for(int j=0;j<=10;j++){
				dp[i][j]=max3(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1])+f[i][j];
				m=max(m,dp[i][j]);
			}
		}
		
		printf("%d\n",m);
	}
	return 0;
}
