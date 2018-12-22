#include <bits/stdc++.h>

using namespace std;

string s[60];
string m[30], f[30];
bool vis[60];
int n, opt[60];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1, j = 1, k = 1; i <= n; i++)
    {
        cin >> opt[i] >> s[i];
    }
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = n; j > n / 2; j--)
        {
            if (opt[i] != opt[j] && vis[j] == 0)
            {
                cout << s[i] << ' ' << s[j] << endl;
                vis[j] = 1;
                break;
            }
        }
    }
    return 0;
}