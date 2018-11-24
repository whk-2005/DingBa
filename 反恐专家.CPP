#include <iostream>
#include <cstdio>
using namespace std;
long long f[25][3];
void init() {
    f[0][0] = 1;
    f[0][1] = f[0][2] = 0;
    for(int i = 1; i <= 25; i++) {
        f[i][0] = 10 * f[i - 1][0] - f[i - 1][1];
        f[i][1] = f[i - 1][0];
        f[i][2] = 10 * f[i - 1][2] + f[i - 1][1];
    }
}
int bit[25];
long long calc(long long n) {
    int len = 0;
    while(n) {
        bit[++len] = n % 10;
        n /= 10;
    }
    bit[len + 1] = 0;
    bool flag = false;
    long long ans = 0;
    for(int i = len; i >= 1; i--) {
        ans += f[i - 1][2] * bit[i];
        if(flag)
            ans += f[i - 1][0] * bit[i];
        else {
            if(bit[i] > 4)
                ans += f[i - 1][1];
        }
        if(bit[i + 1] == 4 && bit[i] == 9)
            flag = true;
    }
    if(flag)
        ans++;
    return ans;
}
int main() {
    int t;
    long long n;
    scanf("%d", &t);
    init();
    while(t--) {
        scanf("%lld", &n);
        printf("%lld\n", calc(n));
    }
    return 0;
}
