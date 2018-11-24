#include <bits/stdc++.h>
using namespace std;
long long dp[100][100],b[100];
long long dfs(long long n,long long t,bool is_max) {
	if(!n)
		return 1;
	if(!is_max && dp[n][t] != -1)
		return dp[n][t];
	long long ans = 0;
	long long m = is_max ? b[n] : 9;
	for(long long i = 0; i <= m; i++) {
		if(!(t == 4 && i == 9))
			ans += dfs(n - 1, i, is_max && i == m);
	}
	if(!is_max)
		dp[n][t] = ans;
	return ans;
} 
long long solve(long long x) {
	long long len;
	for(len = 0; x > 0; x /= 10)
		b[++len] = x % 10;
	return dfs(len, 0, 1);
}
int main() {
	long long t;
	scanf("%lld", &t);
	long long n;
	memset(dp, -1, sizeof(dp));
	while(t--) {
		scanf("%lld", &n);
		printf("%lld\n", n - solve(n) + 1);
	}
	return 0;
}
