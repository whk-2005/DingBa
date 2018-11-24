#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val, len;
    int l, r;
    int lazy;
} tree[200010];
int t, n;
char s[10];
int st, en;
int a[50010];

void build(int root, int l, int r)
{
    int m;
    tree[root].l = l;
    tree[root].r = r;
    tree[root].len = r - l + 1;
    if (l == r)
        tree[root].val = a[l];
    else
    {
        int m = (l + r) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        tree[root].val = tree[root * 2].val + tree[root * 2 + 1].val;
    }
}

void pushdown(int root) 
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

void add(int root, int id, int addval) 
{
    if (tree[root].l == tree[root].r) 
    {
        tree[root].val += addval;
        return;
    }
    else 
    {
        int m = (tree[root].l + tree[root].r) / 2;
        if (id <= m)
            add(root * 2, id, addval);
        else
            add(root * 2 + 1, id, addval);
        tree[root].val = tree[root * 2].val + tree[root * 2 + 1].val;
    }
}

int query(int root, int l, int r) {
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
    ios::sync_with_stdio(false);
    cin >> t;
    for (int Case = 1; Case <= t; Case++)
    {
        memset(tree, 0, sizeof(tree));
        memset(a, 0, sizeof(a));
        printf("Case %d:\n", Case);
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        while (cin >> s)
        {
            if (s[0] == 'E')
                break;
            cin >> st >> en;
            if (s[0] == 'Q')
                printf("%d\n", query(1, st, en));
            if (s[0] == 'A')
                add(1, st, en);
            if (s[0] == 'S')
                add(1, st, -en);
        }
    }
    return 0;
}