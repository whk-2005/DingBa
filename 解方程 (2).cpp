#include <bits/stdc++.h>
using namespace std;
double y;
double l, m, r;
double f(double x) {
	return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%lf", &y);
		if(f(0) <= y && y <= f(100)) {
			l = 0;
			r = 100;
			for(int i = 0; i < 40; i++) {
				m = (l + r) / 2;
				double ans = f(m);
				if(ans > y)
					r = m - 1e-7;
				else
					l = m + 1e-7;
			}
			printf("%.4lf\n", (l + r) / 2);
		}
		else {
			printf("No solution!\n");
		}
	}
	return 0;
}
