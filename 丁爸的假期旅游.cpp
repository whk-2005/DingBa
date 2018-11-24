#include <bits/stdc++.h>
using namespace std;
struct node {
    long long p, daylen, cost, type;
} a[400005];
long long best[100005];
long long t, n, m;
long long l, r, w;
long long ans;
bool cmp(node x, node y) {
    if(x.p != y.p)
        return x.p < y.p;
    return x.type < y.type;
}
int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld%lld", &n, &m);
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= m; i++) {
            scanf("%lld%lld%lld", &l, &r, &w);
            a[i].p = l;
            a[i].daylen = r - l + 1;
            a[i].cost = w;
            a[i].type = -1;
            a[i + m].p = r;
            a[i + m].daylen = r - l + 1;
            a[i + m].cost = w;
            a[i + m].type = 1;
        }
        memset(best, -1, sizeof(best));
        sort(a + 1, a + 2 * m + 1, cmp);
        ans = -1;
        for(int i = 1; i <= 2 * m; i++) {
            if(a[i].type == 1) {
                best[a[i].daylen] = max(a[i].cost, best[a[i].daylen]);
            }
            if(a[i].type == -1 && n - a[i].daylen >= 1 && best[n - a[i].daylen] != -1) {
                ans = max(a[i].cost + best[n - a[i].daylen], ans);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/**
2
5 4
1 3 4
1 3 5
5 6 1
1 2 4
2 3
4 6 3
2 4 1
3 5 4
**/
