#include <bits/stdc++.h>
#define unsinged long long ULL;
using namespace std;
string str[105];
bool vis[105];
int t, n, tot;
bool ok;
bool cmp(string a1, string a2) {
	int len1 = a1.length();
	int len2 = a2.length();
	if(len1 != len2)
		return len1 > len2;
	else
		return a1 > a2;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		cin >> n;
		memset(vis, 0, sizeof(vis));
		ok = 0;
		tot = 1;
		for(int i = 1; i <= n; i++) {
			cin >> str[i];
		}
		sort(str + 1, str + n + 1, cmp);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(j == i)
					continue;
				if(!vis[j]) {
					size_t x = str[i].find(str[j]);
					if(x != string::npos) {
						i = j;
						j = 1;
						vis[j] = 1;
						vis[i] = 1;
						tot++;
						//cout << str[i] << ' ' << str[j] << endl;
					}
					if(tot == n) {
						ok = 1;
						break;
					}
				}
			}
			if(ok == 1)
				break;
		}
		//cout << tot << endl;
		if(ok)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
