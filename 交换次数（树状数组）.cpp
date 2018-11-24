#include <bits/stdc++.h>

using namespace std;

long long n;
long long a[100010];
long long tree[100010];
long long ans;

void add(long long i, long long val)
{
    while (i <= n)
    {
        tree[i] += val;
        i += i & -i;
    }
}

long long query(long long i)
{
    long long ans = 0;
    while (i >= 1)
    {
        ans += tree[i];
        i -= i & -i;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    while (scanf("%lld", &n) == 1)
    {
        ans = 0;
        memset(tree, 0, sizeof(tree));
        for (long long i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            ans += query(n) - query(a[i]);
            add(a[i], 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}