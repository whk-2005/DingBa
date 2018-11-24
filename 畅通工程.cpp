#include<cstdio>
int set[500505];
int findd(int x){
	int r=x;
	while(set[r]!=r) r=set[r];
	return r;
}
void merge(int x,int y){
	int fx=findd(x);
	int fy=findd(y);
	if(fx!=fy) set[fx]=fy;
}
int main(){
	int n,m,x,y,c,i;
	while(scanf("%d%d",&n,&m)==2){
		for(i=1;i<=n;i++) set[i]=i;
		for(;m>0;m--){
			scanf("%d%d",&x,&y);
			merge(x,y);
		}
		for(c=-1,i=1;i<=n;i++){
			if(set[i]==i) c++;
		}
		printf("%d\n",c);
	}
	return 0;
}
