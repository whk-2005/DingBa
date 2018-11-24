#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 10010;
int n, m;
vector<int> Map[MAXN];
int indgr[MAXN], r[MAXN];
LL sum;
void topsort() {
    queue<int> q;
    int num = 0;
    for(int i = 1; i <= n; i++)
        if(indgr[i] == 0)
            q.push(i);
    while(!q.empty()) {
        int nxt = q.front();
        q.pop();
        num++;
        for(int i = 0; i < Map[nxt].size(); i++) {
            indgr[Map[nxt][i]]--;
            if(indgr[Map[nxt][i]] == 0) {
                q.push(Map[nxt][i]);
                r[Map[nxt][i]] = r[nxt] + 1;
            }
        }
    }
    if(num != n)
        printf("-1\n");
    else {
        for(int i = 1; i <= n; i++) {
            sum += (888 + r[i]);
        }
        printf("%lld\n", sum);
    }
}
int main() {
    while(~scanf("%d%d", &n, &m)) {
        int x, y;
        sum = 0;
        memset(indgr, 0, sizeof(indgr));
        memset(r, 0, sizeof(r));
        memset(Map, 0, sizeof(Map));
        for(int i = 1; i <= n; i++)
            Map[i].clear();
        for(int i = 1; i <= m; i++) {
            scanf("%d%d", &x, &y);
            Map[y].push_back(x);
            indgr[x]++;
        }
        topsort();
    }
    return 0;
}
