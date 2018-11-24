#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int w[100005], c[100005];
int f[100005];
int main() {
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            scanf("%d%d", &c[i], &w[i]);
        scanf("%d", &m);
        for(int i = 1; i <= n; ++i) {
            for(int j = w[i]; j <= m; ++j) {
                f[j] = max(f[j], f[j - w[i]] + c[i]);
            }
        }
        printf("%d\n", f[m]);
        memset(w, 0, sizeof(w));
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
    }
    return 0;
}
