#include<bits/stdc++.h>
using namespace std;
int n(int da,int xiao){
	while(xiao!=0){
		int temp=da%xiao;
		da=xiao;
		xiao=temp;
	}
	return da;
}
int main(){
	int m;
	cin>>m; 
	for(int i=0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int x,y;
		x=a*c;
		y=b*d;
		int s=n(x,y);
		cout<<x/s<<" "<<y/s<<endl;
	}
	return 0;
}
