#include <iostream>
using namespace std;
int main() {
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n;
        m = n / 150;
        n = n % 150;
        while(n >= 50 && m >= 1) {
            m--;
            n -= 50;
        }
        cout << n << endl;
    }
    return 0;
}
