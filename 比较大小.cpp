#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[10];
    cin >> a[1] >> a[2] >> a[3];
    sort(a + 1, a + 4);
    printf("%d->%d->%d", a[1], a[2], a[3]);
    return 0;
}