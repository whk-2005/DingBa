#include<iostream>
#include<cmath>
using namespace std;
int n,m,t,si,sj,di,dj,escape;
char Map[9][9];
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
void dfs(int si,int sj,int cnt){
	int temp;
	if(si>n||sj>m||si<=0||sj<=0) return;
	if(cnt==t&&si==di&&sj==dj) escape=1;
	if(escape) return;
	temp=(t-cnt)-abs(si-di)-abs(sj-dj);
	if(temp<0||temp%2==1) return;
	for(int i=0;i<4;i++){
		if(Map[si+dir[i][0]][sj+dir[i][1]]!='X'){
			Map[si+dir[i][0]][sj+dir[i][1]]='X';
			dfs(si+dir[i][0],sj+dir[i][1],cnt+1);
			Map[si+dir[i][0]][sj+dir[i][1]]='.';
		}
	}
	return;
}
int main(){
	while(cin>>n>>m>>t){
		if(n==0&&m==0&&t==0) break;
		int wall=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>Map[i][j];
				if(Map[i][j]=='S'){
					si=i;
					sj=j;
				}
				if(Map[i][j]=='D'){
					di=i;
					dj=j;
				}
				if(Map[i][j]=='X')wall++;
			}
		}
		if(n*m-wall<=t){
			cout<<"NO"<<endl;
			continue;
		}
		escape=0;
		Map[si][sj]='X';
		dfs(si,sj,0);
		if(escape) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
