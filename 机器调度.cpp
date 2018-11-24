#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
int un, vn, k;
int g[MAX][MAX];
int linker[MAX];
bool used[MAX];
bool dfs(int u) {
	for(int v = 0; v < vn; v++) {
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
	for(int u = 0; u < un; u++) {
		memset(used, 0, sizeof(used));
		if(dfs(u))
			res++;	
	}
	return res;
}
int main() {
	while(scanf("%d", &un) == 1 && un) {
		scanf("%d%d", &vn, &k);
		memset(g, 0, sizeof(g));
		int id, u, v;
		while(k--) {
			scanf("%d%d%d", &id, &u, &v);
			if(u != 0 && v != 0)
				g[u][v] = 1;
		}
		printf("%d\n", hungary());
	}
	return 0;
}
