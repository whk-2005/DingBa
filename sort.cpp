#include <bits/stdc++.h>
using namespace std;
bool a[1000005];
int main() {
	int n, m, t;
	while(scanf("%d%d", &n, &m) == 2) {
		memset(a, 0, sizeof(a));
		for(int i = 0; i < n; i++) {
			scanf("%d", &t);
			a[t + 500000] = 1;
		}
		for(int i = 0; i <= 1000000; i++) {
			if(a[i] == 1 && m) {
				printf("%d", i - 500000);
				m--;
			}
			if(m > 1)
				printf(" ");
			if(m == 1)
				break;
		}
		printf("\n");
	}
	return 0;
}
