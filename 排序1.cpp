//==================================================
//date 2018.2.19 
//name ≈≈–Ú 
//auther Wang Hukai 
//==================================================
#include<bits/stdc++.h>
using namespace std;
int a[100];
bool x[100];
void bubblesort(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
				swap(x[j],x[j+1]);
			}
		}
	}
}
int main(){
	int m;
	while(cin>>m&&m!=0){
		memset(x,0,sizeof(x));
		for(int j=0;j<m;j++){
			cin>>a[j];
			if(a[j]<0){
				x[j]=1;
				a[j]*=-1;
			}
		}
		bubblesort(m);
		for(int j=0;j<m;j++){
			if(x[j]==1)cout<<"-";
			if(j!=m-1)cout<<a[j]<<" ";
			else cout<<a[j];
		}
		cout<<endl;
	}
	return 0;
}
