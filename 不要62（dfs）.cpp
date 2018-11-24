#include <bits/stdc++.h>
using namespace std;
int dp[10][10],b[10];
int dfs(int n,int t,bool is_max) {
	if(!n)
		return 1;
	if(!is_max && dp[n][t] != -1)
		return dp[n][t];
	int ans=0;
	int m = is_max ? b[n] : 9;
	for(int i = 0; i <= m; i++) {
		if(i != 4 && !(t == 6 && i == 2))
			ans += dfs(n - 1, i, is_max && i == m);
	}
	if(!is_max)
		dp[n][t] = ans;
	return ans;
} 
int solve(int x) {
	int len;
	for(len = 0; x > 0; x /= 10)
		b[++len] = x % 10;
	return dfs(len, 0, 1);
}
int main() {
	int n, m;
	memset(dp, -1, sizeof(dp));
	while(scanf("%d%d", &n, &m) == 2) {
		if(n == 0 && m == 0)
			break;
		printf("%d\n", solve(m) - solve(n - 1));
	}
	return 0;
}
