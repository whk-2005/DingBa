#include <bits/stdc++.h>
using namespace std;
const int MAX = 50021;
int f[MAX], g[MAX];
int hashh(int k) {
	int t = k % MAX;
	if(t < 0)
		t += MAX;
	while(f[t] != 0 && g[t] != k)
		t = (t + 1) % MAX;
		return t;
}
int main() {
	int a, b, c, d, p, s, n, t[101];
	for(int i = 1; i <= 100; i++)
		t[i] = i * i;
	while(scanf("%d%d%d%d", &a, &b, &c, &d) == 4) {
		if(a > 0 && b > 0 && c > 0 && d > 0 || a < 0 && b < 0 && c < 0 && d < 0) {
			printf("0\n");
			continue;
		}
		memset(f, 0, sizeof(f));
		n = 0;
		for(int i = 1; i <= 100; i++) {
			for(int j = 1; j <= 100; j++) {
				s = a * t[i] + b * t[j];
				p = hashh(s);
				g[p] = s;
				f[p]++;
			}
		}
		for(int i = 1; i <= 100; i++) {
			for(int j = 1; j <= 100; j++) {
				s = -(c * t[i] + d * t[j]);
				p = hashh(s);
				n += f[p];
			}
		}
		printf("%d\n", n * 16);
	}
	return 0;
}
