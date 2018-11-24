#include <bits/stdc++.h>
using namespace std;
set<int> se;
int n, m, t, num;
int main() {
    ios::sync_with_stdio(false);
    while(cin >> n >> m) {
        se.clear();
        for(int i = 1; i <= n + m; i++)
            cin >> t, se.insert(t);
        num = 0;
        for(auto i = se.begin(); i != se.end(); i++) {
            if(num != se.size() - 1)
                cout << *i << ' ', num++;
            else 
                cout << *i;
        }
        cout << endl;
    }
    return 0;
}