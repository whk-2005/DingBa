#include <bits/stdc++.h>
using namespace std;
int f[100];
char str[60][5] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "AJ", "AQ", "AK", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "BJ", "BQ", "BK", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "CJ", "CQ", "CK", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "DJ", "DQ", "DK"};
char s[5];
int n;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    while(n--) {
        for(int i = 0; i < 52; i++)
            f[i] = 0;
        for(int i = 0; i < 51; i++) {
            cin >> s;
            for(int i = 0; i < 52; i++) {
                if(s[0] == str[i][0] && s[1] == str[i][1] && s[2] == str[i][2])
                    f[i] = 1;
            }
        }
        for(int i = 0; i < 52; i++) {
            if(f[i] == 0) {
                cout << str[i] << endl;
                break;
            }
        }
    }
    return 0;
}
