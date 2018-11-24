#include<fstream>
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
//ofstream cout("test.txt");
int main()
{
	int n;
	srand((unsigned)time(NULL));
	/*for(int k=0;k<10000;k++){
        cout<<rand();
	}*/
	cout << rand() * rand() % 4000;
	/*cout<<endl;
	srand((unsigned)time(NULL));
	for(int k=0;k<10000;k++){
        cout<<rand();
	}
	cout<<endl;*/
    return 0;
}
