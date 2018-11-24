#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
char Start[10],End[10];
int fx[8]={-1,-2,-2,-1,1,2,2,1};
int fy[8]={-2,-1,1,2,-2,-1,1,2};
int xStart,yStart,xEnd,yEnd;
bool vis[100][100];
struct node{
	int xfloor,yfloor;
	int step;
};
void bfs(){
	node cur,nex;
	cur.xfloor=xStart;
	cur.yfloor=yStart;
	cur.step=0;
	queue<node>q;
	q.push(cur);
	vis[xStart][yStart]=1;
	while(!q.empty()){
		cur=q.front();
		q.pop();
		if(cur.xfloor==xEnd&&cur.yfloor==yEnd){
			printf("To get from %c%c to %c%c takes %d knight moves.\n",Start[0],Start[1],End[0],End[1],cur.step);
			return;
		}
		for(int i=0;i<8;i++){
			nex.xfloor=cur.xfloor+fx[i];
			nex.yfloor=cur.yfloor+fy[i];
			nex.step=cur.step+1;
			if(nex.xfloor>0&&nex.xfloor<=8&&nex.yfloor>0&&nex.yfloor<=8&&!vis[nex.xfloor][nex.yfloor]){
				vis[nex.xfloor][nex.yfloor]=1;
				q.push(nex);
			}
		}
	}
	return;
}
int main(){
	while(cin>>Start>>End){
		memset(vis,0,sizeof(vis));
		xStart=Start[0]-'a'+1;
		yStart=Start[1]-'1'+1;
		xEnd=End[0]-'a'+1;
		yEnd=End[1]-'1'+1;
		bfs();
	}
	return 0;
}
