#include <bits/stdc++.h>
using namespace std;
const int MAX = 125;
int A, B, t, s, e;
int g[MAX][MAX];
int linker[MAX];
bool used[MAX];
bool dfs(int u) {
	for(int v = 1; v <= A; v++) {
		if(g[u][v] && !used[v]) {
			used[v] = true;
			if(linker[v] == -1 || dfs(linker[v])) {
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
} 
int hungary() {
	int res = 0;
	memset(linker, -1, sizeof(linker));
	for(int u = 1; u <= A; u++) {
		memset(used, 0, sizeof(used));
		if(dfs(u))
			res++;	
	}
	return res;
}
int main() {
	scanf("%d", &t);
	while(t--) {
		memset(g, 0, sizeof(g));
		scanf("%d%d", &A, &B);
		for(int i = 0; i < B; i++) {
			scanf("%d%d", &s, &e);
			g[s][e] = 1;
		}
		printf("%d\n", A - hungary());
	}
	return 0;
}
