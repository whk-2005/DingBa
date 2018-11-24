#include<bits/stdc++.h>
using namespace std;
int a[5900]={0,1},i=1,j=1,k=1,l=1;
int min4(int x,int y,int z,int w){
	return min(x,min(y,min(z,w)));
}
int main(){
	for(int m=2;m<5900;m++){
		a[m]=min4(a[i]*2,a[j]*3,a[k]*5,a[l]*7);
		if(a[m]==a[i]*2) i++;
		if(a[m]==a[j]*3) j++;
		if(a[m]==a[k]*5) k++;
		if(a[m]==a[l]*7) l++;
	}
	int n;
	while(cin>>n&&n!=0){
		cout<<a[n]<<endl;
	}
	return 0;
} 
