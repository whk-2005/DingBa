#include <bits/stdc++.h>
using namespace std;
int n, len, yes;
char a[25];
bool judge() {
    len = strlen(a);
    if(len != 10)
        return 0;
    if(a[0] != 'L' || a[1] != 'Q')
        return 0;
    for(int i = 2; i < 10; i++) {
        if(a[i] < '0' || a[i] > '9')
            return 0;
    }
    return 1;
}
int main() {
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
        gets(a);
        yes = judge();
        if(yes == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
