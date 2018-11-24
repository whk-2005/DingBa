#include<bits/stdc++.h>
using namespace std;
string str;
int num[30];
int bfs(){
	int a,b,sum=0;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=0;i<=26;i++){
		if(num[i]) q.push(num[i]);
	}
	if(q.size()==1) sum=q.top();
	while(q.size()>1){
		a=q.top(); q.pop();
		b=q.top(); q.pop();
		sum+=a+b; q.push(a+b);
	}
	return sum;
}
int main(){
	while(cin>>str){
		if(str=="END") break;
		memset(num,0,sizeof(num));
		int len=str.size();
		for(int i=0;i<len;i++){
			if(str[i]=='_') num[26]++;
			else num[str[i]-'A']++;
		}
		int ans=bfs();
		printf("%d %d %.1f\n",len*8,ans,len*8.0/ans);
	}
	return 0;
}
