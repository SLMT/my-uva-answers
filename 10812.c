/************************************
	Problem ID: UVa 10812
	Programmer: SLMT
	Last Revised Date: 2012/12/11
************************************/
#include <stdio.h>

int main(void) {
	int n, a, b, s, d, rest;
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &s, &d);
		a = (s + d) / 2;
		b = (s - d) / 2;
		rest = ((s + d) % 2)? 1 : ((s - d) % 2)? 1 : 0; /* 檢查 a, b 是否有小數點 */
		
		if (a < 0 || b < 0 || rest == 1)
			printf("impossible\n");
		else
			printf("%d %d\n", a, b);
	}

	return 0;
}