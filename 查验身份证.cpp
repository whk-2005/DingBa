#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int arr[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int m[20] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2};
bool flag, flag1;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        int sum = 0;
        flag = 0;
        cin >> s;
        for (int i = 0; i < 17; i++)
            if (s[i] > '9' || s[i] < '0')
            {
                flag = 1;
                break;
            }
            else
                sum += (s[i] - '0') * arr[i];
        if (flag)
        {
            flag1 = 1;
            cout << s << endl;
        }
        else
        {
            sum %= 11;
            if (s[17] == 'X')
            {
                if (m[sum] != 10)
                    flag1 = 1, cout << s << endl;
            }
            else
            {
                if (s[17] - '0' != m[sum])
                    flag1 = 1, cout << s << endl;
            }
        }
    }
    if (flag1 == 0)
        printf("All passed\n");
    return 0;
}