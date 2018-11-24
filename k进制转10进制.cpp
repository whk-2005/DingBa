//==================================================
//date 2018.2.18
//name k进制转10进制 
//auther Wang Hukai 
//================================================== 
#include<bits/stdc++.h>
#define n 7
using namespace std;
long long int zh(char a[],int k){
	int s=0,num;
	for(int i=0;a[i]!='\0';i++){
		if(a[i]>='0'&&a[i]<k+'0'){
			num=a[i]-'0';
		}
		else{
			if(k>10&&(a[i]>='a'&&a[i]<='a'+k-11)){
				num=a[i]-'a'+10;
			}
			else{
				if(k>10&&(a[i]>='A'&&a[i]<='A'+k-11)){
					num=a[i]-'A'+10;
				}
				else{
					s=-1;
					break;
				}
			}
		}
		s=s*k+num;
	}
	return s;
}
int main(){
	char a[n+1];
	int k;
	while(scanf("%s%d",a,&k)==2){
		long long b=zh(a,k);
		if(b!=-1) cout<<b<<endl;
		else cout<<"Error!"<<endl;
	}
}
