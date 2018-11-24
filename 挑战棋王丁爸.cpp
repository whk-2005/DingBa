#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y;
    int step;
    /*friend bool operator < (const node &a, const node &b) {
        a.step < b.step;
    }*/
};
int n, m, x1, y11, x2, y2;
int change[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char _map[12][12];
int vis[12][12];
void bfs() {
    queue<node> q;
    node cnt, nxt;
    cnt.x = x1;
    cnt.y = y11;
    cnt.step = 0;
    vis[x1][y11] = 1;
    q.push(cnt);
    while(!q.empty()) {
        cnt = q.front();
        q.pop();
        if(cnt.x == x2 && cnt.y == y2) {
            printf("%d\n", cnt.step);
            return;
        }
        for(int i = 0; i < 4; i++) {
            int xx = cnt.x + change[i][0];
            int yy = cnt.y + change[i][1];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && _map[xx][yy] == '.' && !vis[xx][yy]) {
                vis[xx][yy] = 1;
                nxt.x = xx;
                nxt.y = yy;
                nxt.step = cnt.step + 1;
                q.push(nxt);
            }
            else if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && _map[xx][yy] == '*' && !vis[xx][yy]) {
                xx = xx + change[i][0];
                yy = yy + change[i][1];
                if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && _map[xx][yy] == '.' && !vis[xx][yy]) {
                    vis[xx][yy] = 1;
                    nxt.x = xx;
                    nxt.y = yy;
                    nxt.step = cnt.step + 1;
                    q.push(nxt);
                }
            }
        }
    }
    printf("-1\n");
    return;
}
int main() {
    while(scanf("%d%d", &n, &m) == 2) {
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++) {
            getchar();
            for(int j = 1; j <= m; j++) {
                _map[i][j] = getchar();
            }
        }
        scanf("%d%d%d%d", &x1, &y11, &x2, &y2);
        bfs();
    }
    return 0;
}
