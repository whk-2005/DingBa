#include<bits/stdc++.h>
using namespace std;
int a[22][12],minn[22][11];
int main(){
	int n,m;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				minn[i][j]=99999999;
			}
		}
		for(int i=1;i<=m;i++){
			minn[1][i]=0;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=m;k++){
					minn[i][j]=min(minn[i][j],minn[i-1][k]+abs(a[i][j]-a[i-1][k]));
				}
			}
		}
		int ans=99999999;
		for(int i=1;i<=m;i++){
			ans=min(ans,minn[n][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
