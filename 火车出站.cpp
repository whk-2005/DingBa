#include <cstdio>
#include <cstring>
using namespace std;
int n, a[100], b[100], stack[100], out[100];
char aa[100], bb[100];
int num, top, outn;
int main() {
	while (~scanf("%d%s%s", &n, aa, bb)) {
		num = 0, top = 1; outn = 0;
		memset(out, 0 , sizeof(out));
		memset(stack, 0, sizeof(stack));
		stack[0] = -1;
		for (int i = 0; i < n; i ++) {
			a[i] = aa[i] - '0';
		}
		for (int i = 0; i < n; i ++) {
			b[i] = bb[i] - '0';
		}
		for (int i = 0; i < n; i ++) {
			stack[top ++] = a[i];
			out[outn ++] = 1;
			while (stack[top - 1] == b[num]) {
				top --;
				num ++;
				out[outn ++] = 2;
			}
		}
		if (num == n) {
			printf("Yes.\n");
			for (int i = 0; i < outn; i ++) {
				if (out[i] == 1)
					printf("in\n");
				if (out[i] == 2)
					printf("out\n");
			}
			printf("FINISH\n");
		}
		else {
			printf("No.\n");
			printf("FINISH\n");
		}
	}
	return 0;
}