#include<cstdio>
#include<cstring>
using namespace std;
int a[1001],f[1001];
int n,max;
int main(){
	while(scanf("%d",&n)&&n!=0){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		max=-1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			f[i]=a[i];
			for(int j=1;j<i;j++){
				if(a[i]>a[j]&&f[i]<f[j]+a[i]){
					f[i]=f[j]+a[i];
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(max<f[i]){
				max=f[i];
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
