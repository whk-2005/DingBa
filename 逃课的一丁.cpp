#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,k;
bool vis[200010];
struct node{
	int data,step;
};
void bfs(){
	queue<node>q;
	node cur,nex;
	cur.data=n;
	cur.step=0;
	q.push(cur);
	vis[n]=1;
	while(!q.empty()){
		cur=q.front();
		q.pop();
		if(cur.data==k){
			cout<<cur.step<<endl;
			return;
		}
		nex.data=cur.data+1;
		nex.step=cur.step+1;
		if(vis[nex.data]==0&&nex.data<=100000&&nex.data>=0){
			vis[nex.data]=1;
			q.push(nex);
		}
		nex.data=cur.data-1;
		nex.step=cur.step+1;
		if(vis[nex.data]==0&&nex.data<=100000&&nex.data>=0){
			vis[nex.data]=1;
			q.push(nex);
		}
		nex.data=cur.data*2;
		nex.step=cur.step+1;
		if(vis[nex.data]==0&&nex.data<=100000&&nex.data>=0){
			vis[nex.data]=1;
			q.push(nex);
		}
	}
}
int main(){
	while(cin>>n>>k){
		memset(vis,0,sizeof(vis));
		bfs();
	}
	return 0;
}
