#include<bits/stdc++.h>
using namespace std;
int p=1,q=1;
int temp[1000],k;
void power(int a,int b){
	k=2;
	temp[0]=1;
	temp[1]=1;
	for(int i=2;i<1000;i++){
		temp[i]=temp[i-1]*a+temp[i-2]*b;
		temp[i]%=7;
		if((temp[i]==temp[1])&&(temp[i-1]==temp[0])) break;
		k++;
	}
	k--;
} 
int main(){
	int a,b,n;
	while(cin>>a>>b>>n&&(a!=0||b!=0||n!=0)){
		power(a,b);
		/*cout<<k<<endl;
		for(int i=0;i<1000;i++){
			cout<<temp[i]<<" ";
		}
		cout<<endl;*/
		int t=n%k-1;
		if(t==-1) t=k-1;
		cout<<temp[t]<<endl;
	}
	return 0;
}
