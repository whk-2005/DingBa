#include <bits/stdc++.h>

using namespace std;

int n, a, b;
int x[1000], pos;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a, &b);
        if (a == 1)
            x[pos++] = b;
        else
        {
            int ans = 0;
            sort(x, x + pos, cmp);
            for (int j = 0; j < pos && x[j] > b; j++)
                ans++;
            printf("%d\n", ans + 1);
        }
    }
    return 0;
}