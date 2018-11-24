#include <bits/stdc++.h>
using namespace std;
const int MAX = 305;
int c1[MAX], c2[MAX];
int n;
int main() {
	while(cin >> n && n) {
		for(int i = 0; i <= n; i++) {
			c1[i] = 0;
			c2[i] = 0;
		}
		for(int i = 0; i <= n; i++) 
			c1[i] = 1;
		for(int i = 2; i <= n; i++) {
			for(int j = 0; j <= n; j++) {
				for(int k = 0; j + k <= n; k += i * i) {
					c2[j + k] += c1[j];
				}
			}
			for(int j = 0; j <= n; j++) {
				c1[j] = c2[j];
				c2[j] = 0;
			} 
		}
		cout << c1[n] << endl;
	}
	return 0;
} 
