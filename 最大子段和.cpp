#include<cstdio>
#include<cstring>
using namespace std;
int a[100001],f[100001];
int t,n,max,head,tail,start,end;
int main(){
	scanf("%d",&t);
	for(int l=1;l<=t;l++){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		max=-2100000000;
		start=end=0;
		head=tail=-1;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			if(f[i-1]>=0){
				end=i;
				f[i]=f[i-1]+a[i];
			}
			else{
				start=i;
				end=i;
				f[i]=a[i];
			}
			if(f[i]>=max){
				max=f[i];
				head=start;
				tail=end;
			}
		}
    	printf("Case %d:\n",l);
    	printf("%d %d %d\n",max,head+1,tail+1);
    	if(l!=t){
    		printf("\n");
		}
	}
	return 0;
}
