#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
int n, s, t, ans;
int linker[MAX];
int g[MAX][MAX];
int used[MAX];
bool dfs(int u) {
    for(int v = 1; v <= n; v++) {
        if(g[u][v] && !used[v]) {
            used[v] = 1;
            if(linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary() {
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for(int u = 1; u <= n; u++) {
        memset(used, 0, sizeof(used));
        if(dfs(u))
            res++;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        memset(g, 0, sizeof(g));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if((i + s) % j == 0)
                    g[i][j] = 1;
            }
        }
        ans = hungary();
        if(ans != n)
            cout << "too bad" << endl;
        else
            cout << "very good" << endl;
    }
    return 0;
}
