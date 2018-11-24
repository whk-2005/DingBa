#include <bits/stdc++.h>

using namespace std;

int a;
int main(int argc, char const *argv[])
{
    while (scanf("%d", &a) == 1)
    {
        if (a == 0)
            break;
        printf("%d\n", a & -a);
    }
    return 0;
}