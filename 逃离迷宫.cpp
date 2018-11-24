#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
char str[105][105];
int id[105][105];
int n,m;
int k,x1,y5,x2,y2;
int dir[4][2]={-1,0,1,0,0,-1,0,1};
int flag;
struct node
{
    int x,y,k;
};
void bfs()
{
    node t;
    t.x=x1;
    t.y=y5;
    t.k=-1;
    id[x1][y5]=1;
    queue<node> q;
    q.push(t);
    while(q.empty()==0)
    {
        node t1;
        t1=q.front();
        q.pop();
        if(t1.x==x2&&t1.y==y2&&t1.k<=k)
        {
            //cout<<t1.k<<endl;
            flag=true;
        }

        for(int i=0;i<4;i++)
        {
            node t2;
            t2.x=t1.x+dir[i][0];
            t2.y=t1.y+dir[i][1];
            while(t2.x>=1&&t2.x<=n&&t2.y>=1&&t2.y<=m&&str[t2.x][t2.y]!='*')
            {

                if(id[t2.x][t2.y]==0)
                {
                    t2.k=t1.k+1;
                    id[t2.x][t2.y]=1;
                    q.push(t2);
                }
                node t3;
                t3.x=t2.x+dir[i][0];
                t3.y=t2.y+dir[i][1];
                t2=t3;
            }
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf(" %c",&str[i][j]);
            }
        }
        memset(id,0,sizeof(id));
        scanf("%d%d%d%d%d",&k,&y5,&x1,&y2,&x2);
        flag=false;
        bfs();
        if(flag==true)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

