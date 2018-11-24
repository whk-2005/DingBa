#include <iostream>
#include <cstring>
using namespace std;
int T,N,K,n[8],v[8],a[42],b[42],last,last2;
int main() {
	cin>>T;
	while((T--)!=0) {
		cin>>N>>K;
		for(int i=0; i<K; i++)
			cin>>v[i]>>n[i];
		a[0]=1;
		last=0;
		for(int i=0;i<K;i++) {
			last2=min(last+n[i]*v[i],N);
			memset(b,0,sizeof(int)*(last2+1));
			for(int j=0;j<=n[i]&&j*v[i]<=last2;j++)
				for(int k=0; k<=last&&k+j*v[i]<=last2; k++)
					b[k+j*v[i]]+=a[k];
			memcpy(a,b,sizeof(int)*(last2+1));
			last=last2;
		}
		cout<<a[N]<<endl;
	}
	return 0;
}
