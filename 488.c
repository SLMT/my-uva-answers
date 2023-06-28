/************************************
	Problem ID: UVa 488, TPC 7072
	Programmer: SLMT
	Last Revised Date: 2013/2/20
************************************/
#include <stdio.h>

int main(void) {
	int n, a, f, times, i, j, k;
	
	scanf("%d", &n);
	for (times = 0 ; times < n; times++) {
		scanf("%d %d", &a, &f);
		for (i = 0; i < f; i++) { /* 碭猧 */
			/* 场蛤い丁 */
			for (j = 1; j <= a; j++) { /* –猧碭糷 */
				for (k = 1; k <= j; k++) /* –糷碭 */
					printf("%d", j);
				printf("\n");
			}
			/* 场 */
			for (j = a - 1; j >= 0; j--) { /* –猧碭糷 */
				for (k = 1; k <= j; k++) /* –糷碭 */
					printf("%d", j);
				if (times == n - 1 && i == f - 1 && j == 0) /* ňゎ程︽传︽ */
					;/* do nothing */
				else
					printf("\n");
			}
		}
	}
	
	return 0;
}