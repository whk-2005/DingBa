#include<bits/stdc++.h>
using namespace std;
struct student{
	int math,chi,data;
}a[50];
bool cmp(student a,student b){
	int s1=a.math+a.chi,s2=b.math+b.chi;
	if(s1!=s2) return s1>s2;
	else return a.math>b.math;
}
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i].data>>a[i].math>>a[i].chi;
		}
		sort(a,a+n,cmp);
		int x;
		cin>>x;
		for(int i=0;i<n;i++){
			if(a[i].data==x){
				cout<<i+1<<endl;
				break;
			}
		}
	}
	return 0;
}
