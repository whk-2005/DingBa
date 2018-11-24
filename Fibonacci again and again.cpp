#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
int sg[MAX], f[20], hashh[MAX];
int n, m, p;
void SG() {
	f[0] = f[1] = 1;
	for(int i = 2; i <= 16; i++) 
		f[i] = f[i - 1] + f[i - 2];
	memset(sg, 0, sizeof(sg));
	for(int i = 1; i <= 1000; i++) {
		memset(hashh, 0, sizeof(hashh));
		for(int j = 1; f[j] <= i; j++) {
			hashh[sg[i - f[j]]] = 1;
		}
		for(int j = 0; j <= 1000; j++) {
			if(hashh[j] == 0) {
				sg[i] = j;
				break;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	SG();
	while(cin >> n >> m >> p && n && m && p) {
		if(sg[n] ^ sg[m] ^ sg[p])
			cout << "Fibo" << endl;
		else
			cout << "Nacci" << endl;
	}
	return 0;
}
