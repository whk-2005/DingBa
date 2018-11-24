#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int root[1005];
int n,m,ans;
bool ok0;
struct node{
    int x,y;
}a[500505];
bool cmp(node aa,node bb){
    if(aa.x!=bb.x) return aa.x<bb.x;
    return aa.y<bb.y;
}
void join(int x,int y){
	int i=min(root[x],root[y]);
	int j=max(root[x],root[y]);
	for(int k=1;k<=n;k++){
		if(root[k]==j) root[k]=i;
	}
	return;
}
int main(){
	int x,y;
	while(scanf("%d%d",&n,&m)==2){
		ans=0;
		for(int i=0;i<=n;i++){
			root[i]=i;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			//if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
		}
		//sort(a,a+m,cmp);
		for(int i=0;i<m;i++){
			join(a[i].x,a[i].y);
		}
		for(int i=1;i<=n;i++){
			if(root[i]!=0) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

