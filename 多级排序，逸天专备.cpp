#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	char name[15];
	int age;
	double score;
}student[105];
int string_min(char a[],char b[]){
	int lena=strlen(a);
	int lenb=strlen(b);
	int temp=max(lena,lenb);
	for(int i=0;i<=temp;i++){
		if(a[i]!=b[i]){
			if(a[i]>b[i]) return 0;
			else return 1;
		}
	}
}
bool cmp(node a,node b){
	if(a.score!=b.score) return a.score>b.score;
	if(a.age!=b.age) return a.age<b.age;
	return string_min(a.name,b.name);
}
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			scanf("%s%d%lf",&student[i].name,&student[i].age,&student[i].score);
		}
		sort(student,student+n,cmp);
		for(int i=0;i<n;i++){
			printf("%s %d %.2lf\n",student[i].name,student[i].age,student[i].score);
		}
	}
	return 0;
}
