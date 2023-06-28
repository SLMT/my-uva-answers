/************************************
	Problem ID: UVa 11984, TPC 7069
	Programmer: SLMT
	Last Revised Date: 2013/2/19
************************************/
#include <stdio.h>

int main(void) {
	int T, i;
	double c, f, ans;
	
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%lf %lf", &c, &f);
		ans = c + (f * 5 / 9);
		printf("Case %d: %.2f\n", i + 1, ans);
	}

	return 0;
}