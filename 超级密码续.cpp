#include<bits/stdc++.h>
using namespace std;
char a[1000][11];
int main(){
	int n;
	while(cin>>n){
		if(n==0){
			break;
		}
		int maxa=-1;
		gets(a[0]);
		for(int i=0;i<n;i++){
			gets(a[i]);
			int temp=0;
			for(int j=0;a[i][j]!='\0';j++){
				if(a[i][j]>='0'&&a[i][j]<='9'){
					temp=temp*10+(int)(a[i][j]-'0');
				}
			}
			if(temp>maxa){
				maxa=temp;
			}
		}
		cout<<maxa<<endl;
	}
	return 0;
}
