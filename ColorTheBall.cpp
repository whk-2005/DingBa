#include <bits/stdc++.h>

using namespace std;

int n, a, b;
int d[100010];

int main(int argc, char const *argv[])
{
    while (scanf("%d", &n))
    {
        if (n == 0)
            break;
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &a, &b), d[a] += 1, d[b + 1] -= 1;
        int tmp = 0;
        for (int i = 1; i < n; i++)
            printf("%d ", tmp += d[i]);
        printf("%d\n", tmp += d[n]);
    }
    return 0;
}
