#include <iostream>
using namespace std;
const int MAX=100000000;
int map[200][200];
void hahaha(int n){    
    int a,b,c;
    for(c=0;c<n;c++)
        for(a=0;a<n;a++)
            for(b=0;b<n;b++)
                if(map[a][c]+map[c][b]<map[a][b])
                    map[a][b]=map[a][c]+map[c][b];
}
int main(){
    int n,m;
    while(cin>>n>>m){
        for(int i=0;i<200;i++)
            for(int j=0;j<200;j++)
                map[i][j]=MAX;
		for(int i=0;i<200;i++)map[i][i]=0;
		int from,to,length;
		while(m--)
		{
			cin>>from>>to>>length;
			if(length<map[from][to])
			map[from][to]=length,map[to][from]=length;
		}
		hahaha(n);
		cin>>from>>to;
		if(map[from][to]==MAX)cout<<-1<<endl;
		else cout<<map[from][to]<<endl;
    }
    return 0;
}

