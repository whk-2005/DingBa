#include <bits/stdc++.h>
using namespace std;
int num = 1, n;
long long _map[40][40];
int main() {
	ios::sync_with_stdio(false);
	for(int i = 1; i <= 38; i++) {
		_map[i][1] = 1;
		for(int j = 2; j <= i; j++) {
			_map[i][j] = _map[i - 1][j] + _map[i][j - 1];
		}
	}
	while(cin >> n) {
		if(n == -1)
			break;
		cout << num << ' ' << n << ' ' << _map[n + 1][n + 1] * 2 << endl;
		num++;
	}
	return 0;
}
