#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005];
int m = 0;

vector<int> v;

int main()
{
    while (scanf("%d", &n) == 1)
    {
        v.clear();
        for (int i = 1; i <= n; i++)
        {
            int f, x;
            scanf("%d%d", &f, &x);
            x = -x;
            if (f == 1)
                v.insert(upper_bound(v.begin(), v.end(), x), x);
            else
                printf("%d\n", lower_bound(v.begin(), v.end(), x) - v.begin() + 1);
        }
    }
    return 0;
}