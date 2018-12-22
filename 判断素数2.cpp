#include <bits/stdc++.h>

using namespace std;

bool check(int n)
{
    if (n == 1 || n == 0)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    int tmp = sqrt(n) + 1;
    for (int i = 3; i <= tmp; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n, a;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &a);
        if (check(a))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}