#pragma GCC optimize ("O2") 
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node{
	int r,c;
	int energy;
	friend bool operator <(const node& a,const node& b){
		return a.energy>b.energy;
	}
};
int R,C,rs,cs,rd,cd,n;
char Map[1005][1005];
int vis[1005][1005];
int change[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
void bfs(){
	priority_queue<node>q;
	node cur,nxt;
	cur.r=rs;
	cur.c=cs;
	cur.energy=0;
	q.push(cur);
	while(!q.empty()){
		cur=q.top();
		q.pop();
		if(cur.r==rd&&cur.c==cd){
			printf("%d\n",cur.energy);
			return;
		}
		for(int i=0;i<8;i++){
			nxt.r=cur.r+change[i][0];
			nxt.c=cur.c+change[i][1];
			if(nxt.r>=1&&nxt.r<=R&&nxt.c>=1&&nxt.c<=C){
				if(i==(int)Map[cur.r][cur.c]-'0'){
					nxt.energy=cur.energy;
				}
				else{
					nxt.energy=cur.energy+1;
				}
				if(nxt.energy<vis[nxt.r][nxt.c]){
					vis[nxt.r][nxt.c]=nxt.energy;
					q.push(nxt); 
				}
			}
		}
	}
}
int main(){
	while(scanf("%d%d",&R,&C)==2){
		for(int i=1;i<=R;i++){
			getchar();
			for(int j=1;j<=C;j++){
				scanf("%c",&Map[i][j]);
			}
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int i=1;i<=R;i++){
				for(int j=1;j<=C;j++){
					vis[i][j]=99999999;
				}
			}
			scanf("%d%d%d%d",&rs,&cs,&rd,&cd);
			vis[rs][cs]=0;
			bfs();
		}
	}
	return 0;
}
