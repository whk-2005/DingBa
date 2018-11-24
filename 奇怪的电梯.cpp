#include<iostream>
#include<queue>
using namespace std;
int a[201];
bool vis[201];
int n,Start,End;
struct node{
	int floor;
	int step;
};
void bfs(){
	node cur,nex;
	cur.floor=Start;
	cur.step=0;
	queue<node>q;
	q.push(cur);
	vis[Start]=1;
	while(!q.empty()){
		cur=q.front();
		q.pop();
		if(cur.floor==End){
			cout<<cur.step<<endl;
			return;
		}
		nex.floor=cur.floor+a[cur.floor];
		nex.step=cur.step+1;
		if(nex.floor<=n){
			if(vis[nex.floor]==0){
				vis[nex.floor]=1;
				q.push(nex);
			}
		}
		nex.floor=cur.floor-a[cur.floor];
		nex.step=cur.step+1;
		if(nex.floor>=1){
			if(vis[nex.floor]==0){
				vis[nex.floor]=1;
				q.push(nex);
			}
		}
	}
	cout<<"-1"<<endl;
	return;
}
int main(){
	while(cin>>n){
		if(n==0) return 0;
		cin>>Start>>End;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			vis[i]=0;
		}
		bfs();
	}
}
