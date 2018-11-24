#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
bool b[1000][1000];
int main(){
	int m,n;
	while(cin>>m>>n){
		memset(b,0,sizeof(b));
		int maxa=-1,maxb,maxc;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				if(a[i][j]<0){
					a[i][j]*=-1;
					b[i][j]=1;
				}
				if(a[i][j]>maxa){
					maxa=a[i][j];
					maxb=i;
					maxc=j;
				}
			}
		}
		cout<<maxb+1<<" "<<maxc+1<<" ";
		if(b[maxb][maxc]==1) cout<<"-";
		cout<<maxa<<endl;
	}
	return 0;
}
