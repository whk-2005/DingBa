#include<bits/stdc++.h>
using namespace std;
bool judgment(int a){
	if(a==2) return true;
	if(a%2==0) return false;
	for(int i=3;i*i<=a;i+=2){
		if(a%i==0) return false;
	}
	return true;
}
int main(){
	int a,b;
	while(cin>>a>>b&&a!=0||b!=0){
		bool n=1;
		for(int i=a;i<=b;i++){
			int x;
			x=i*i+i+41;
			if(judgment(x)==false){
				cout<<"Sorry"<<endl;
				n=0;
				break;
			}
		}
		if(n) cout<<"OK"<<endl;
	}
	return 0;
}
