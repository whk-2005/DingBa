#include <bits/stdc++.h>

using namespace std;

int vis[150];
int ok[10010];
string a, b;

int main()
{
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < b.length(); i++)
        vis[b[i]] = 1;
    for (int i = 0; i < a.length(); i++)
    {
        if (vis[a[i]])
            ok[i] = 1;
    }
    for (int i = 0; i < a.length(); i++)
    {
        if (ok[i] == 0)
            cout << a[i];
    }
    return 0;
}