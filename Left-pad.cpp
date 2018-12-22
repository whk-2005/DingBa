#include <bits/stdc++.h>

using namespace std;

int n;
char c;
string s;

int main()
{
    cin >> n >> c;
    getchar();
    getline(cin, s);
    if (s.length() <= n)
    {
        for (int i = 1; i <= n - s.length(); i++)
            cout << c;
        cout << s << endl;
    }
    else
    {
        for (int i = s.length() - n; i <= s.length(); i++)
            cout << s[i];
        cout << endl;
    }
}