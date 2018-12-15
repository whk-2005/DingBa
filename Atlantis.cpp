#include <bits/stdc++.h>

using namespace std;

const int N = 20010;
struct node
{
    double x;
    double l, r;
    int flag;
    bool operator<(const node a) const
    {
        return x < a.x;
    }
    node() {}
    node(double x, double y1, double y2, int f) : x(x), l(y1), r(y2), flag(f) {}
} line[N];
int n;
double tr[N];
double yy[N];
int cover[N];
int yl, yr, v;

void pushup(int root, int l, int r)
{
    if (cover[root] > 0)
        tr[root] = yy[r + 1] - yy[l];
    else if (l == r)
        tr[root] = 0;
    else
        tr[root] = tr[root << 1] + tr[root << 1 | 1];
}

void update(int root, int l, int r)
{
    if (yl > r || yr < l)
        return;
    if (yl <= l && yr >= r)
    {
        cover[root] += v;
        pushup(root, l, r);
        return;
    }
    if (yl <= (l + r) >> 1)
        update(root << 1, l, (l + r) >> 1);
    if (yr > (l + r) >> 1)
        update(root << 1 | 1, ((l + r) >> 1) + 1, r);
    pushup(root, l, r);
}

int main()
{
    while (~scanf("%d", &n) && n)
    {
        int cnt = 0;
        double x1, y1, x2, y2;
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            line[++cnt] = node(x1, y2, y1, 1);
            yy[cnt] = y1;
            line[++cnt] = node(x2, y2, y1, -1);
            yy[cnt] = y2;
        }
        sort(yy + 1, yy + cnt + 1);
        sort(line + 1, line + cnt + 1);
        int len = unique(yy + 1, yy + cnt + 1) - yy - 1;
        memset(cover, 0, sizeof cover);
        memset(tr, 0, sizeof tr);
        double ans = 0;
        for (int i = 1; i <= cnt; ++i)
        {
            ans += tr[1] * (line[i].x - line[i - 1].x);
            yl = lower_bound(yy + 1, yy + len + 1, line[i].r) - yy;
            yr = lower_bound(yy + 1, yy + len + 1, line[i].l) - yy - 1;
            v = line[i].flag;
            update(1, 1, len - 1);
        }
        printf("%.2f\n", ans);
    }
    return 0;
}