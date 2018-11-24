#include <bits/stdc++.h>

using namespace std;

int tree[50010];
int a[50010];
int t, n;
char s[10];
int st, en;

void add(int i, int val)
{
    while (i <= n)
    {
        tree[i] += val;
        i += i & -i;
    }
}

int query(int i)
{
    int ans = 0;
    while (i >= 1)
    {
        ans += tree[i];
        i -= i & -i;
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    for (int Case = 1; Case <= t; Case++)
    {
        memset(tree, 0, sizeof(tree));
        printf("Case %d:\n", Case);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), add(i, a[i]);
        while (scanf("%s", s))
        {
            if (s[0] == 'E')
                break;
            scanf("%d%d", &st, &en);
            if (s[0] == 'Q')
                printf("%d\n", query(en) - query(st - 1));
            if (s[0] == 'A')
                add(st, en);
            if (s[0] == 'S')
                add(st, -en);
        }
    }
    return 0;
}