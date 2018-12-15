#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n;
ll a[110], b[110];
ll ansa, ansb, ansc;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    ansb = 1;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld/%lld", &a[i], &b[i]);
    for (int i = 1; i <= n; i++)
    {
        ansa = ansa * b[i] + a[i] * ansb;
        ansb = ansb * b[i];
        ll _gcd = gcd(ansa, ansb);
        ansa /= _gcd, ansb /= _gcd;
    }
    ansc = ansa / ansb;
    ansa %= ansb;
    ll _gcd = gcd(ansa, ansb);
    ansa /= _gcd, ansb /= _gcd;
    if (ansc)
        printf("%lld", ansc);
    if (ansc && ansa)
        printf(" ");
    if (ansa)
        printf("%lld/%lld", ansa, ansb);
    if (ansa == 0 && ansb == 1 && ansc == 0)
        printf("0");
    return 0;
}