#include<bits/stdc++.h>
using namespace std;
struct whk{
	int s,t;
}a[200];
int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n,max=0,b[202]={0};
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j].s>>a[j].t;
			if(a[j].s>a[j].t){
				swap(a[j].s,a[j].t);
			}
			for(int m=(a[j].s+1)/2;m<=(a[j].t+1)/2;m++){
				b[m]++;
			}
		}
		for(int k=0;k<202;k++){
			if(b[k]>max){
				max=b[k];
			}
		}
		cout<<max*10<<endl;
	}
	return 0;
}
