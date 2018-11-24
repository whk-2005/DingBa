#include<bits/stdc++.h>
using namespace std;
int a[200][200],f[200][200],max1;
int main(){
	int m,n;
	while(cin>>n>>m){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				max1=0;
				for(int k=0;k<=j;k++){
					if(f[i-1][k]+a[i][j-k]>max1) max1=f[i-1][k]+a[i][j-k];
				}
				f[i][j]=max1;
			}
		}
		cout<<f[n][m]<<endl;
	}
	return 0;
}
