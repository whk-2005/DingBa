#include <bits/stdc++.h>
using namespace std;
const int MAXN = 520;
int g[MAXN][MAXN], indgr[MAXN], res[MAXN];
void topsort(int n) {
    int k = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!indgr[j]) {
                res[i] = j;
                indgr[j]--;
                k = j;
                break;
            }
        }
        for(int j = 1; j <= n; j++) {
            if(g[k][j] == 1) {
                g[k][j] = 0;
                indgr[j]--;
            }
        }
    }
}
void print(int n) {
    for(int i = 1; i <= n; i++)
        if(i < n)
            printf("%d ", res[i]);
        else
            printf("%d\n", res[i]);
}
int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        int x, y;
        memset(indgr, 0, sizeof(indgr));
        memset(g, 0, sizeof(g));
        for(int i = 1; i <= m; i++) {
            scanf("%d%d", &x, &y);
            if(!g[x][y]) {
                g[x][y] = 1;
                indgr[y]++;
            }
        }
        topsort(n);
        print(n);
    }
    return 0;
}
