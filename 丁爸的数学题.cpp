#include <bits/stdc++.h>
using namespace std;
long long t, n, k;
bool cmp(long long a, long long b) {
    return a < b;
}
long long prime() {
    int temp;
    long long a[200] = {0, 1};
    if(n != 1)
        a[2] = n, temp = 3;
    else
        temp = 2;
    /**
     *����1������
     *9 ~ 13
     *   long long a[200] = {0, 1, n);
     *   temp = 3;
     *n == 1, a[1] == 1, a[2] == 1;
     *so, k == 1, print 1; k == 2, print 1(ԭ��Ϊ-1�ı�Ϊ��1......)
     *WA!!!!!
    **/
    for(int i = 2; 1LL * i * i <= n; i++) {
        if(n % i == 0) {
            a[temp] = i;
            if(i != n / i) {
                a[temp + 1] = n / i;
                temp += 2;
            } else {
                temp++;
            }
        }
    }
    /**
     *for(int i = 2; i * i <= n; i++)
     *TLE!!!!!
     *i * i���ܴ���2147483647, so, 1LL(int -> long long)
     *else i * i ��Զ�޷� > n
    **/
    if(temp <= k)
        return -1;
    sort(a + 1, a + temp, cmp);
    if(temp > k)
        return a[k];
}
int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld%lld", &n, &k);
        printf("%lld\n", prime());
    }
    return 0;
}
