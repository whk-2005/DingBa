#include <bits/stdc++.h>

using namespace std;

int n;
double h, w;
double stdd;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> h >> w;
        w /= 2;
        stdd = (h - 100) * 0.9;
        if (fabs(w - stdd) < stdd * 0.1)
            cout << "You are wan mei!" << endl;
        if (w - stdd <= stdd * -0.1)
            cout << "You are tai shou le!" << endl;
        if (w - stdd >= stdd * 0.1)
            cout << "You are tai pang le!" << endl;
    }
    return 0;
}