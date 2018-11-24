#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    int len;
    int lazy;
    int l, r;
} tree[400010];
int arr[100010];
int n, m;
int x, y, z;
int t;

void build(int root, int l, int r)
{
    int m;
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

void pushdown(int root)
{
    if (tree[root].lazy)
    {
        tree[root * 2].lazy = tree[root].lazy;
        tree[root * 2 + 1].lazy = tree[root].lazy;
        tree[root * 2].val = tree[root * 2].len * tree[root].lazy;
        tree[root * 2 + 1].val = tree[root * 2 + 1].len * tree[root].lazy;
        tree[root].lazy = 0;
    }
}

void update(int root, int l, int r, int addval)
{
    if (tree[root].l >= l && tree[root].r <= r)
    {
        tree[root].lazy = addval;
        tree[root].val = tree[root].len * addval;
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

int query(int root, int l, int r)
{
    int mid;
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
    scanf("%d", &t);
    while (t--)
    {
        memset(tree, 0, sizeof(tree));
        scanf("%d", &n);
        build(1, 1, n);
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            update(1, x, y, z);
        }
        printf("%d\n", query(1, 1, n));
    }
    return 0;
}