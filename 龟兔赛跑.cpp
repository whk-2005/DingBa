#include<bits/stdc++.h>
using namespace std;
double f[200];
int a[200];
int main(){
	int l,n,c,t,vr,vt1,vt2;
	while(scanf("%d%d%d%d%d%d%d",&l,&n,&c,&t,&vr,&vt1,&vt2)==7){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		double tr=l*1.0/vr;
		a[n+1]=l;
		for(int i=1;i<=n+1;i++){
			double minn=2100000000;
			for(int j=0;j<i;j++){
				int len=a[i]-a[j];
				double temp;
				bool bd;
				if(len>c){
					temp=1.0*c/(vt1*1.0)+(len-c)/(vt2*1.0);
					bd=true;
				}
				else{
					temp=len*1.0/vt1;
					bd=false;
				}
				if(j){
					temp+=t;
				}
				if(minn>temp+f[j]){
					minn=temp+f[j];
				}
			}
			f[i]=minn;
		}
		if(tr>f[n+1]) cout<<"What a pity rabbit!"<<endl;
		else cout<<"Good job,rabbit!"<<endl;
	}
	return 0;
}
