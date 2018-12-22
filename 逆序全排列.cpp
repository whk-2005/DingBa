#include <bits/stdc++.h>

using namespace std;

int n;
int a[10];

int main()
{
    while(scanf("%d", &n) == 1)
    {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        printf("\n");
        while (prev_permutation(a + 1, a + n + 1))
        {
            for (int i = 1; i <= n; i++)
                printf("%d ", a[i]);
            printf("\n");
        }
    }
    return 0;
}