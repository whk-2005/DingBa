#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        if(n % (m + 1))
            cout << "first" << endl;
        else
            cout << "second" << endl;
    }
    return 0;
}
