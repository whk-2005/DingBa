#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long val;
    long long len;
    long long lazy;
    long long l, r;
} tree[400010];
long long arr[100010];
long long n, m, q;
long long x, y, z;
long long t;

void build(long long root, long long l, long long r)
{
    long long m;
    tree[root].lazy = 0;
    tree[root].l = l;
    tree[root].r = r;
    tree[root].len = r - l + 1;
    if (l == r)
        tree[root].val = 1;
    else
    {
        m = (l + r) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        tree[root].val = (tree[root * 2].val + tree[root * 2 + 1].val);
    }
}

void pushdown(long long root)
{
    if (tree[root].lazy)
    {
        tree[root * 2].lazy += tree[root].lazy;
        tree[root * 2 + 1].lazy += tree[root].lazy;
        tree[root * 2].val += tree[root * 2].len * tree[root].lazy;
        tree[root * 2 + 1].val += tree[root * 2 + 1].len * tree[root].lazy;
        tree[root].lazy = 0;
    }
}

void update(long long root, long long l, long long r, long long addval)
{
    if (tree[root].l >= l && tree[root].r <= r)
    {
        tree[root].lazy += addval;
        tree[root].val += tree[root].len * addval;
        return;
    }
    if (tree[root].l > r || tree[root].r < l)
        return;
    if (tree[root].lazy)
        pushdown(root);
    update(root * 2, l, r, addval);
    update(root * 2 + 1, l, r, addval);
    tree[root].val = (tree[root * 2].val + tree[root * 2 + 1].val);
}

long long query(long long root, long long l, long long r)
{
    long long mid;
    if (tree[root].l >= l && tree[root].r <= r)
        return tree[root].val;
    if (tree[root].l > r || tree[root].r < l)
        return 0;
    if (tree[root].lazy)
        pushdown(root);
    return query(root * 2, l, r) + query(root * 2 + 1, l, r);
}

int main(int argc, char const *argv[])
{
    scanf("%lld", &t);
    while (t--)
    {
        memset(tree, 0, sizeof(tree));
        scanf("%lld%lld%lld", &n, &m, &q);
        build(1, 1, n);
        for (int i = 1; i <= m; i++)
        {
            scanf("%lld%lld%lld", &x, &y, &z);
            update(1, x, y, z);
        }
        for (int i = 1; i <= q; i++)
        {
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", query(1, x, y));
        }
    }
    return 0;
}