#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double arr[50][5],s1[50],s2[5],s3[50],s4[5];
int main(){
	int n,m;//¿Î£¬Ñ§Éú 
	while(cin>>m>>n){
		memset(arr,0,sizeof(arr));
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(s3,0,sizeof(s3));
		memset(s4,0,sizeof(s4));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
				s1[i]+=arr[i][j];
				s2[j]+=arr[i][j];
			}
		}
		for(int i=0;i<m;i++){
			s3[i]=s1[i]/n;
			if(i!=m-1) printf("%.2lf ",s3[i]);
			else printf("%.2lf",s3[i]);
		}
		cout<<endl;
		for(int i=0;i<n;i++){
			s4[i]=s2[i]/m;
			if(i!=n-1) printf("%.2lf ",s4[i]);
			else printf("%.2lf",s4[i]);
		}
		cout<<endl;
		int k=0;
		for(int i=0;i<m;i++){
			bool p=true;
			for(int j=0;j<n;j++){
				if(arr[i][j]<s4[j]) p=false;
			}
			if(p) k++;
		}
		cout<<k<<endl<<endl;
	}
	return 0;
}
