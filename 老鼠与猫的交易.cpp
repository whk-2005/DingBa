#include<bits/stdc++.h>
using namespace std;
struct whk{
	double a,b,c;
}x[1000];
int cmp(whk a,whk b){
	return a.c>b.c;
}
int main(){
	int m,n;
	while(cin>>m>>n&&(m!=-1||n!=-1)){
		double s=0;
		for(int i=0;i<n;i++){
			cin>>x[i].a>>x[i].b;
			x[i].c=x[i].a/x[i].b;
		}
		sort(x,x+n,cmp);
		for(int i=0;i<n;i++){
			if(m>=x[i].b){
				m-=x[i].b;
				s+=x[i].a;
			}
			else{
				s+=m*x[i].c;
				break;
			}
		}
		printf("%.3lf\n",s);
	}
	return 0;
}
