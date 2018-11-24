#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,lon[70],sum,goal;
bool vis[70];
bool cmp(int a,int b){
	return a>b;
}
bool dfs(int now, int index, int cnt){
    if(goal*cnt==sum) return true;
    for(int i=index;i<n;i++){
        if(vis[i]||(i&&!vis[i-1]&&lon[i]==lon[i-1])) continue;
        if(now+lon[i]==goal){
            vis[i]=true;
            if(dfs(0,0,cnt+1)) return true;
            vis[i]=false;
            return false;
        }
		else if(now+lon[i]<goal){
            vis[i]=true;
            if(dfs(now+lon[i],i+1,cnt)) return true;
            vis[i]=false;
            if(now==0) return false;
        }
    }
    return false;
}
int main(){
	//freopen("ÕÅìÓµÄ½ð¹¿°ô.in","r",stdin);
	while(scanf("%d",&n)==1){
		if(n==0) break;
		sum=0;
		int maxx=0;
		for(int i=0;i<n;i++){
			vis[i]=0;
			scanf("%d",&lon[i]);
			sum+=lon[i];
		}
		sort(lon,lon+n,cmp);
		for(goal=maxx+1;goal<=sum;goal++){
			if(sum%goal==0){
				memset(vis,0,sizeof(vis));
				if(dfs(0,0,0)){
					printf("%d\n",goal);
					break;
				}
			}
		}
	}
	return 0;
}
