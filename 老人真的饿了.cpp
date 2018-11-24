#include<bits/stdc++.h>
using namespace std;
struct whk{
	double a,b;
}x[1000];
int cmp(whk a,whk b){
	return a.a<b.a;
}
int main(){
	int n,c;
	double m;
	scanf("%d",&c);
	for(int j=0;j<c;j++){
		//cin>>m>>n;
		scanf("%lf%d",&m,&n);
		double s=0;
		for(int i=0;i<n;i++){
			//cin>>x[i].a>>x[i].b;
			scanf("%lf%lf",&x[i].a,&x[i].b);
		}
		sort(x,x+n,cmp);
		for(int i=0;i<n;i++){
			if(m>=x[i].a*x[i].b){
				m-=x[i].a*x[i].b;
				s+=x[i].b;
			}
			else{
				s+=m/x[i].a;
				break;
			}
		}
		printf("%.2f\n",s);
	} 
	return 0;
}
