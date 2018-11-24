#include<bits/stdc++.h>
using namespace std;
char a[250];
int main(){
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
		scanf("%s",a);
		int s; 
		cin>>s;
		int len=strlen(a);
		bool temp=0;
		for(int i=0;i<s;i++){
			for(int j=0;j<len-1;j++){
				if(a[j]>a[j+1]){
					for(int k=j;k<len-1;k++){
						a[k]=a[k+1];
					}
					break;
				}
			}
			len--;
		}
		for(int i=0;i<len;i++){
			if(a[i]!=0){
				temp=1;
			}
			if(temp){
				cout<<a[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
