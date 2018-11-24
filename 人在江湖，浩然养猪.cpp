#include<iostream>
using namespace std;
long long ans[50][6]={{0,0,0,0,0,0},{0,1,0,0,0,1}};
int main(){
	for(int i=2;i<=45;i++){
		ans[i][1]=ans[i-1][2]*4+ans[i-1][3]*4+ans[i-1][4]*4;
		ans[i][2]=ans[i-1][1];
		ans[i][3]=ans[i-1][2];
		ans[i][4]=ans[i-1][3];
		ans[i][5]=ans[i][1]+ans[i][2]+ans[i][3]+ans[i][4]+ans[i-1][4];
	}
	int n,a;
	cin>>n;
	/*for(int i=1;i<=40;i++){
		cout<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<" "<<ans[i][4]<<" "<<ans[i][5]<<endl;
	}*/
	while(n--){
		cin>>a;
		cout<<ans[a][5]<<endl;
	}
	return 0;
}
//    1   2   3   4   5   6   7   8   9   10  11  12
//1   1       4   4   16 
//2       1       4   4
//3           1       4   8
//4               1       4
//
//s   1   1   5   9   24  
