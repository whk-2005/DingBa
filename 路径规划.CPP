#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int m,n;
int per[125];

struct node{
	int u,v;
	int w;
}s[10010];

bool cmp(node a,node b)
{
	return a.w<b.w;
}

void itoa()
{
	for(int i=0;i<=n;i++)
		per[i]=i;
}

int findd(int x)
{
	if(x==per[x])
		return x;
	return findd(per[x]);
}

bool join(int a,int b)
{
	int fa=findd(a);
	int fb=findd(b);
	if(fb!=fa)
	{
		per[fa]=fb;
		return true;
	}
	return false;
}

int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++){
			scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].w);
		}
		sort(s,s+m,cmp);
		itoa();
		int sum=0;
		int howlong=0;
		for(i=0;i<m;i++)
		{
			if(join(s[i].u,s[i].v))
			{
				sum+=s[i].w;
				howlong=max(howlong,s[i].w);
			}
		}

		printf("%d %d\n",sum,howlong);
	}
	return 0;
}
