#include<bits/stdc++.h>
using namespace std;
const int MAX=1061109567;
int road,link,want,total;
int e[1010][1010],linkarr[1010],wantarr[1010],dis[1010];
bool visit[1010];
void Dijkstra(int start)
{
	std::ios::sync_with_stdio(false);
    int temp,k;
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=total;i++)
        dis[i]=e[start][i];
    dis[start]=0;
    visit[start]=1;
    for(int i=1;i<=total;i++)
    {
        temp=MAX;
        for(int j=1;j<=total;j++)
            if(!visit[j]&&temp>dis[j])
                temp=dis[k=j];
        visit[k]=1;
        for(int j=1;j<=total;j++)
            if(!visit[j]&&dis[j]>dis[k]+e[k][j])
                dis[j]=dis[k]+e[k][j];
    }
}
int main()
{
    int x,y,cost,minn,answer;
    while(cin>>road>>link>>want)
    {
        total=0;
        memset(e,MAX,sizeof(e));
        for(int i=1;i<=road;i++)
        {
            scanf("%d%d%d",&x,&y,&cost);
            if(cost<e[x][y])
                e[x][y]=e[y][x]=cost;
            total=max(total,max(x,y)); 
        }
        for(int i=1;i<=link;i++) 
            cin>>linkarr[i];
        for(int i=1;i<=want;i++)
            cin>>wantarr[i];
        answer=MAX;
        for(int i=1;i<=link;i++)
        {
            Dijkstra(linkarr[i]);
            minn=MAX;
            for(int j=1;j<=want;j++)
                if(dis[wantarr[j]]<minn)
                    minn=dis[wantarr[j]];
            if(answer>minn)
                answer=minn;
        }
        cout<<answer<<endl;
    }
}
