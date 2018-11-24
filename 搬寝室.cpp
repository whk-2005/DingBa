#include<bits/stdc++.h>
using namespace std;
int f[3][1002];
int a[2002];
int dp(int n,int k)
{
    int i,j;
    memset(f,0,sizeof(f));
    for(i=2;i<=n;i++)
		for(j=1;j<=k&&j*2<=i;j++)
	    {
	        if(j*2==i)
	        f[i%3][j]=f[(i-2)%3][j-1]+(a[i-1]-a[i])*(a[i-1]-a[i]);
	        else
	        f[i%3][j]=min(f[(i-1)%3][j],f[(i-2)%3][j-1]+(a[i-1]-a[i])*(a[i-1]-a[i]));
	    }
}
int main()
{
    int i;
    int n,k;
    while(cin>>n>>k)
    {
        a[0]=0;
        for(i=1;i<=n;i++)
        	cin>>a[i];
        sort(a,a+n+1);
        dp(n,k);
        cout<<f[n%3][k]<<endl;
    }
    return 0;
}
