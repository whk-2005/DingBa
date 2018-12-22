#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
int n;
int a[maxn];
int f[maxn];
int l, r, mid;
int ans1, ans2;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    f[0] = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (f[ans1] >= a[i])
        {
            f[ans1 + 1] = a[i]; 
            ans1++;
        }
        else
        {
            l = 0;
            r = ans1;
            while (l < r)
            {
                mid = (l + r) / 2;
                if (f[mid] >= a[i])
                    l = mid + 1;
                else
                {
                    r = mid;
                }
            }
            if (l != 0)
                f[l] = a[i];
        }
    }
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        if (f[ans2] < a[i])
        {
            f[ans2 + 1] = a[i];
            ans2++;
        }
        else
        {
            l = 0;
            r = ans2;
            while (l < r)
            {
                mid = (l + r) / 2;
                if (f[mid] >= a[i])
                    r = mid;
                else
                {
                    l = mid + 1;
                }
            }
            f[l] = a[i];
        }
    }
    cout << ans2 << endl;
    return 0;
}