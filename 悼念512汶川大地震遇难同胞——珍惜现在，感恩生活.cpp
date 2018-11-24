#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int v[105], w[105], s[105];
int f[105];
int n, m, c;
int main() {
    scanf("%d", &c);
    while(c--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &v[i], &w[i], &s[i]);
        }
        for(int i = 1; i <= m; ++i) {
            for(int j = n; j >= 0; --j) {
                for(int k = 0; k <= s[i]; ++k) {
                    if(j - k * v[i] < 0)
                        break;
                    f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
                }
            }
        }
        printf("%d\n", f[n]);
        memset(v, 0, sizeof(v));
        memset(w, 0, sizeof(w));
        memset(s, 0, sizeof(s));
        memset(f, 0, sizeof(f));
    }
    return 0;
}
