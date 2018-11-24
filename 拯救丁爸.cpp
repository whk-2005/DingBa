#include<bits/stdc++.h>
using namespace std;

struct sta{
	int x,y,time;
	friend bool operator < (const sta &x,const sta &y){
		return x.time>y.time;
	}
};

int vis[205][205],n,m,start_x,start_y;
int change[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char Map[205][205];

int bfs(){
	priority_queue<sta>q;
	sta cur,nxt;
	cur.x=start_x;
	cur.y=start_y;
	cur.time=0;
	q.push(cur);
	while(!q.empty()){
		cur=q.top();
		q.pop();
		if(Map[cur.x][cur.y]=='r'){
			return cur.time;
		}
		for(int k=0;k<4;k++){
			nxt.x=cur.x+change[k][0];
			nxt.y=cur.y+change[k][1];
			if(nxt.x>=1&&nxt.x<=n&&nxt.y>=1&&nxt.y<=m){
				if(vis[nxt.x][nxt.y]==0){
					vis[nxt.x][nxt.y]=1;
					if(Map[nxt.x][nxt.y]=='x'){
						nxt.time=cur.time+2;
						q.push(nxt);
					}
					else if(Map[nxt.x][nxt.y]=='.'||Map[nxt.x][nxt.y]=='r'){
						nxt.time=cur.time+1;
						q.push(nxt);
					}
				}
			}
		}
	}
	return 0;
}

int main(){
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>Map[i][j];
				if(Map[i][j]=='a'){
					start_x=i;
					start_y=j;
				}
			}
		}
		memset(vis,0,sizeof(vis));
		int res=bfs();
		if(res==0){
			cout<<"Poor Dingba has to stay in the prison all his life." <<endl;
		}
		else{
			cout<<res<<endl;
		}
	}
	return 0;
}
