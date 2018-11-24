#include <bits/stdc++.h>
using namespace std;
bool f1[100005];
bool f2[100005];
int num[100005];
int t, n;
void f() {
    for(int i = 4; i <= 100000; i += 2)
        f1[i] = 1;
    for(int i = 3; i <= 100000; i += 2) {
        for(int j = 3; j * j <= i; j += 2) {
            if(f1[j] == 0) {
                if(i % j == 0) {
                    f1[i] = 1;
                    break;
                }
            }
        }
    }
    for(int i = 5; i <= 100000; i++) {
        if(f1[i] == 0 && f1[i - 2] == 0) {
            num[i] = num[i - 1] + 1;
        }
        else {
            num[i] = num[i - 1];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    f();
    cin >> t;
    while(t--) {
        cin >> n;
        cout << num[n] << endl;
    }
    return 0;
}
