#include<iostream>
using namespace std;
const int INF=0x7fffffff;
const int M=201;
int Map[M][M],dist[M],vis[M];
int main(){
	int n,m,startt,endd,dis,a,b,Min,nxt;
	while(cin>>n>>m){
		for(int i=0;i<n;i++){
			vis[i]=1;
			dist[i]=INF;
			for(int j=0;j<n;j++) Map[i][j]=INF;
		}
		while(m--){
			cin>>a>>b>>dis;
			Map[a][b]=min(Map[a][b],dis);
			Map[b][a]=Map[a][b];
		}
		cin>>startt>>endd;
		dist[startt]=0;
		vis[startt]=0;
		while(startt!=endd){
			Min=INF;
			for(int i=0;i<n;i++){
				if(Map[startt][i]!=INF)
					dist[i]=min(dist[i],Map[startt][i]+dist[startt]);
				if(vis[i]&&dist[i]<Min){
					nxt=i;
					Min=dist[i];
				}
			}
			if(Min==INF) break;
			startt=nxt;
			vis[startt]=0;
		}
		if(dist[endd]==INF) cout<<"-1"<<endl;
		else cout<<dist[endd]<<endl;
	}
	return 0;
}
