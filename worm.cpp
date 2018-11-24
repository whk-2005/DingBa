#include<cstdio>
#include<cstring>
using namespace std;
int a[101][101];
int n,p,m,t;
int main(){
	while(scanf("%d%d%d%d",&n,&p,&m,&t)==4){
		memset(a,0,sizeof(a));
		if(p<n) a[1][p+1]=1;
		if(p>1) a[1][p-1]=1;
		for(int i=2;i<=m;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=a[i-1][j-1]+a[i-1][j+1];
			}
		}
		printf("%d\n",a[m][t]);
	}
	return 0;
}
