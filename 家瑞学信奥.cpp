#include <bits/stdc++.h>
using namespace std;
long long a[100005], dp[100005];
long long n, t, ans, tt;
long long maxx(long long xx, long long yy) {
    if(xx > yy)
        return xx;
    return yy;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> tt;
    while(tt--) {
        ans = -1;
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            cin >> t;
            a[t]++;
        }
        for(int i = 1; i <= 100004; i++) {
            dp[i] = i * a[i];
            if(i >= 2)
                dp[i] = maxx(dp[i], dp[i - 1]);
            if(i >= 3)
                dp[i] = maxx(dp[i], dp[i - 2] + i * a[i]);
            if(i >= 4)
                dp[i] = maxx(dp[i], dp[i - 3] + (i - 1) * a[i - 1]);
            //ans = maxx(ans, dp[i]);
        }
        //cout << ans << endl;
        cout << dp[n] << endl;
    }
    return 0;
}
