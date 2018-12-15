#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int n, m, t;
set<int> s[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            int x;
            scanf("%d", &x);
            s[i].insert(x);
        }
    }
    scanf("%d", &t);
    while (t--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        set<int> res;
        set_intersection(s[x].begin(), s[x].end(), s[y].begin(), s[y].end(), inserter(res, res.begin()));
        int nc = res.size();
        int nt = s[x].size() + s[y].size() - res.size();
        printf("%.2f%%\n", 100.0 * nc / nt);
    }
    return 0;
}