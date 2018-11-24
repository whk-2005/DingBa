#include <bits/stdc++.h>
using namespace std;
long long a[25][25];
int m, n;
int main() {
	ios::sync_with_stdio(false);
	for(int i = 1; i <= 20; i++) {
		a[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}
	while(cin >> m >> n) {
		cout << a[m][n] << endl;
	}
}
