#include <bits/stdc++.h>

using namespace std;

int n, a[1000005], c[1000005];
long long ans;

void sort_(int l, int r)
{
    int mid = (l + r) / 2, i, j, tmp;
    if (r > l)
    {
        sort_(l, mid);
        sort_(mid + 1, r);
        tmp = l;
        for (i = l, j = mid + 1; i <= mid && j <= r;)
        {
            if (a[i] > a[j])
            {
                c[tmp++] = a[j++];
                ans += mid - i + 1;
            }
            else
                c[tmp++] = a[i++];
        }
        if (i <= mid)
            for (; i <= mid;)
                c[tmp++] = a[i++];
        if (j <= r)
            for (; j <= r;)
                c[tmp++] = a[j++];
        for (i = l; i <= r; i++)
            a[i] = c[i];
    }
}
int main()
{
    while (scanf("%d", &n) == 1)
    {
        ans = 0;
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort_(1, n);
        printf("%lld\n", ans);
    }
    return 0;
}