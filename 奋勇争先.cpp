#include<bits/stdc++.h>
using namespace std;
struct student{
	char name[20];
	int num,time;
}a[1000];
bool cmp(student a,student b){
	if(a.num!=b.num) return a.num>b.num;
	return a.time<b.time;
}
int main(){
	int c;
	cin>>c;
	for(int j=0;j<c;j++){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a[i].name>>a[i].num>>a[i].time;
		}
		int numa=-1,timea=2147483647;
		sort(a,a+n,cmp);
		for(int i=0;i<k;i++){
			cout<<a[i].name<<" "<<a[i].num<<" "<<a[i].time<<endl;
		}
		cout<<endl;
	}
	return 0;
}
