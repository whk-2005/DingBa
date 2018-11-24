#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int l[100000];
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int k=1;
		l[k]=a[0];
		for(int i=1;i<n;i++){
			int p=0;
			for(int j=0;j<=k;j++){
				if(l[j]>=a[i]){
					if(p==0) p=j;
					else if(l[j]<l[p]) p=j;
				}
			}
			if(p==0){
				k++;
				l[k]=a[i];
			}
			else l[p]=a[i];
		}
		cout<<k<<endl;
	}
	return 0;
}
