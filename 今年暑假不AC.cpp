#include<bits/stdc++.h>
using namespace std;
struct time1{
	int start,end;
}a[100];
bool cmp(time1 x,time1 y){
	return x.end<y.end;
}
int main(){
	int n;
	while(cin>>n&&n!=0){
		int end1=0,s=0;
		for(int i=0;i<n;i++){
			cin>>a[i].start>>a[i].end;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			if(a[i].start>=end1){
				end1=a[i].end;
				s++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
} 
