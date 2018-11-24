#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	while(cin>>a>>b){
		int s1=0,s2=0;
		if(a>b) swap(a,b);
		for(int i=a;i<=b;i++){
			if(i%2==0){
				s1+=i*i;
			}
			else{
				s2+=i*i*i;
			}
		}
		printf("%d %d\n",s1,s2);
	}
	return 0;
}
