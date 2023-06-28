/************************************
	Problem ID: UVa 12149, TPC 7071
	Programmer: SLMT
	Last Revised Date: 2013/2/20
************************************/
#include <stdio.h>

int main(void) {
	int n, ans;
	
	while (scanf("%d", &n) == 1 && n != 0) {
		/* N x N 的正方形數剛好是 1^2 + 2^2 ... + N^2 */
		ans = n * (n + 1) * (2 * n + 1) / 6;
		printf("%d\n", ans);
	}
	
	return 0;
}