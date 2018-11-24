#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct point
{
    int u;
    int v;
    int w;
}a[5000];
bool comp(point a1,point a2)
{
    return a1.w<a2.w;
}
int n,m,father[100],t,cnt;
int find(int x)
{
    if(father[x]!=x)
        father[x]=find(father[x]);
    return father[x];
}
void merge(int x,int y)
{
    int p=find(x);
    int q=find(y);
    if(p<q)
        father[q]=p;
    else
        father[p]=q;
}
void initial()
{
    for(int i=1;i<=n;i++)
        father[i]=i;
}
int Kruskal()
{
    int ans=0;
    sort(a,a+m,comp);
    for(int i=0;i<m;i++)
    {
        int x=find(a[i].u);
        int y=find(a[i].v);
        if(x!=y)
        {
            ans+=a[i].w;
            merge(x,y);
        }
    }
    return ans;
}
int main()
{
    int i,sum,b,c,d,sta;
    while(~scanf("%d",&n)&&n)
    {
        initial();
        m=n*(n-1)/2;
        for(i=0,t=0;i<m;i++)
        {
            scanf("%d%d%d%d",&b,&c,&d,&sta);
            a[i].u=b;
            a[i].v=c;
            if(sta==0)
                a[i].w=d;
            else
                a[i].w=0;
        }
        sum=Kruskal();
        printf("%d\n",sum);
    }
    return 0;
}
