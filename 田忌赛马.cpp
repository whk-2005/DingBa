#include<bits/stdc++.h>
using namespace std;
double a[1000],b[1000];
bool cmp(double i,double j){
	return i>j;
}

int main(){
	int n;
	while(cin>>n&&n!=0){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		int s=0;
		for(int i=0;i<n;i++){
			bool t=0;
			for(int j=i;j<n;j++){
				if(a[i]>b[j]&&a[i]!=-1&&b[j]!=-1){
					t=1;
					s+=200;
					a[i]=-1;
					b[j]=-1;
					break;
				}
			}
			if(t==0){
				s-=200;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
