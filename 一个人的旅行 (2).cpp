#include<bits/stdc++.h>
using namespace std;
const int maxn=1050;
const int INF=0x7ffffff;
struct Edge {
     int from, to, dist;
     Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
 }; 
struct HeapNode {
     int d, u;
     HeapNode(int dv, int uv) :d(dv), u(uv){}
     bool operator < (const HeapNode& rhs) const {
         return d > rhs.d;
     }
 };
struct Dijkstra {
     int n, m;
     Dijkstra(){};
     Dijkstra(int nv, int mv) :n(nv), m(mv){}
     vector<Edge> edges;
     vector<int> G[maxn];
     bool done[maxn];
     int d[maxn];
     void init(int n) {
         this->n = n;
         for (int i=0; i < n; i++) G[i].clear();
         edges.clear();
     }
     void AddEdge(Edge e){
         edges.push_back(e);
         m = edges.size();
         G[e.from].push_back(m - 1);
     }
     void dijkstra(int s){
         priority_queue<HeapNode> Q;
         for(int i=0;i<n;i++) d[i] = INF;
         d[s]=0;
         memset(done,0,sizeof(done));
         Q.push(HeapNode(0,s));
         while (!Q.empty()){
             HeapNode x=Q.top();Q.pop();
             int u=x.u;
             if(done[u]) continue;
             done[u]=true;
             for (int i=0;i<G[u].size();i++){
                 Edge& e=edges[G[u][i]];
                 if (d[e.to]>d[u]+e.dist){
                     d[e.to]=d[u]+e.dist;
                     Q.push(HeapNode(d[e.to],e.to));
                 }
             }
         }
     }
 };
 int ad[maxn];
 int wt[maxn];
 int main(){
     int T,S,D,t,a,b,r,ans,temp;
     Dijkstra d;
     while (scanf("%d%d%d",&T,&S,&D)==3){
         ans=INF;
         d.init(1005);
         for(int i=0;i<T;i++){
             scanf("%d%d%d",&a,&b,&t);
             d.AddEdge(Edge(a-1,b-1,t));
             d.AddEdge(Edge(b-1,a-1,t));
         }
         for(int i=0;i<S;i++) scanf("%d",&ad[i]);
         for(int i=0;i<D;i++) scanf("%d",&wt[i]);
         for(int i=0;i<S;i++)
         {
             d.dijkstra(ad[i]-1);
             for(int j=0;j<D;j++)
             {
                 if(ans>d.d[wt[j]-1]) ans=d.d[wt[j]-1];
             }
         }
         printf("%d\n",ans);
     }
 }
