#include <bits/stdc++.h>
using namespace std;
const int MAX = 10005;
int c1[MAX], c2[MAX], a[MAX];
vector<int>ans;
int n, s;
int main() {
	while(cin >> n) {
		s = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		memset(c1,0,sizeof c1);
		memset(c2,0,sizeof c2);
		for(int i = 0;i <= 1 && i * a[0] <= s; i++) {
			c1[i * a[0]] = 1;
			c2[i * a[0]] = 0;
		}
		for(int i = 1; i < n; i++) {
			for(int j = 0; j <= s; j++) {
				for(int k = 0; j + k * a[i] <= s && k <= 1; k++) {
					c2[j + k * a[i]] += c1[j];
					c2[abs(j - k * a[i])] += c1[j];
				}
			}
			for(int j = 0; j <= s; j++) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		int num = 0;
		for(int i = 0; i <= s; i++) {
			if(c1[i] == 0) {
				num++;
			}
		}
		cout << num << endl;
		int tot = 0;
		for(int i = 0; i <= s; i++) {
			if(c1[i] == 0) {
				tot++;
				if(tot == 1)
					cout << i;
				else
					cout << ' ' << i;
			}
		}
		if(num)
			cout << endl;
	}
	return 0;
}
