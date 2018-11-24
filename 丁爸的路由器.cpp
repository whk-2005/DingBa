#include <bits/stdc++.h>
using namespace std;
int a[35][35];
int t;
int m, n, k;
bool yes, ok;
int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		ok = 0;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		for(int i = 1; i <= n - k + 1; i++) {
			for(int j = 1; j <= m - k + 1; j++) {
				yes = 1;
				for(int x = i; x <= i + k - 1; x++) {
					for(int y = j; y <= j + k - 1; y++) {
						if(a[x][y] != 0) {
							yes = 0;
							break;
						}
					}
				}
				if(yes == 1) {
					cout << "Yes\n";
					ok = 1;
					break;
				}
			}
			if(ok == 1)
				break;
		}
		if(ok == 0)
			cout << "No\n";
	}
	return 0;
}
