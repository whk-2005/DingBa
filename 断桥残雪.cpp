#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct node
{
    ll l, r, add;
} a[4000010];
ll n, m, k;
ll l, r, opt;

void bulid(ll p, ll l, ll r)
{
    a[p].l = l;
    a[p].r = r;
    if (l == r)
    {
        a[p].add = INT_MAX;
        return;
    }
    ll mid = (l + r) / 2;
    bulid(p * 2, l, mid);
    bulid(p * 2 + 1, mid + 1, r);
    a[p].add = min(a[p * 2].add, a[p * 2 + 1].add);
}

void add(ll p, ll v, ll x)
{
    if (v == a[p].l && a[p].l == a[p].r)
    {
        a[p].add = x;
        return;
    }
    ll mid = (a[p].l + a[p].r) / 2;
    if (v <= mid)
        add(p * 2, v, x);
    else
        add(p * 2 + 1, v, x);
    a[p].add = min(a[p * 2].add, a[p * 2 + 1].add);
    return;
}

ll query(ll p, ll l, ll r)
{
    if (l <= a[p].l && a[p].r <= r)
        return a[p].add;
    ll mid = (a[p].l + a[p].r) / 2, ans = INT_MAX;
    if (l <= mid)
        ans = min(query(p * 2, l, r), ans);
    if (mid + 1 <= r)
        ans = min(query(p * 2 + 1, l, r), ans);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    bulid(1, 0, m + m);
    for (int i = 1; i <= n; i++)
    {
        cin >> opt >> l >> r;
        if (opt == 1)
            add(1, l + m, r);
        else
        {
            int ans = query(1, l + m, r + m);
            if (ans == INT_MAX)
                cout << -1 << endl;
            else
                cout << ans << endl;
        }
    }
    return 0;
}