#include<bits/stdc++.h>
using namespace std;
struct whk{
	int date,score;
}a[1000];
bool cmp(whk x,whk y){
	if(x.score!=y.score) return x.score>y.score;
	return x.date<y.date;
}
bool work[1000];
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j].date;
			work[j]=0;
		}
		for(int j=0;j<n;j++){
			cin>>a[j].score;
		}
		int s=0;
		sort(a,a+n,cmp);
		/*for(int j=0;j<n;j++){
			cout<<a[j].date<<" "<<a[j].score<<endl;
		}*/
		for(int j=0;j<n;j++){
			bool yes=false;
			for(int k=a[j].date-1;k>=0;k--){
				if(work[k]==0){
					work[k]=1;
					yes=true;
					break;
				}
			}
			if(yes==false){
				s+=a[j].score;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
