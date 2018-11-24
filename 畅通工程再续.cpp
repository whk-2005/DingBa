#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n;
int per[125];
double x[125],y[125];

struct node{
	int u,v;
	double w;
}s[10010];

bool cmp(node a,node b)
{
	return a.w<b.w;
}

void itoa()
{
	for(int i=0;i<=n;++i)
		per[i]=i;
}

int find(int x)
{
	if(x==per[x])
		return x;
	return find(per[x]);
}

bool join(int a,int b)
{
	int fa=find(a);
	int fb=find(b);
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
		scanf("%d",&n);
		for(i=0;i<n;++i)
			scanf("%lf%lfd",&x[i],&y[i]);
		int k=0;
		double d;
		for(i=0;i<n-1;++i)
		{
			for(j=i+1;j<n;++j)
			{
				d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				if(d>=10&&d<=1000)
				{
					s[k].u=i;
					s[k].v=j;
					s[k].w=d;
					k++;
				}
			}
		}

		sort(s,s+k,cmp);
		itoa();
		int flag=0;
		double sum=0;

		for(i=0;i<k;++i)
		{
			if(join(s[i].u,s[i].v))
			{
				sum+=s[i].w;
				flag++;
			}
		}

		if(flag==n-1)
			printf("%.1lf\n",sum*100);
		else
			printf("oh!\n");
	}
	return 0;
}
