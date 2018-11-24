#include <bits/stdc++.h>
using namespace std;
int x[1005], y[1005];
bool cmp(int a, int b) {
    return a < b;
}
int main() {
    int n, m, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
            y[i] += x[i];
        }
        sort(y, y + n, cmp);
        int u, tt = y[0], ans = 0;
        for(int j = 0; j < n; j++) {
            tt = y[j];
            u = 1;
            for(int i = j + 1; i < n; i++) {
                if(y[i] >= tt + m) {
                    tt = y[i];
                    u++;
                }
            }
            ans = max(ans, u);
        }
        printf("%d\n", ans);
    }
    return 0;
}
