/************************************
	Problem ID: UVa 661
	Programmer: SLMT
	Last Revised Date: 2012/11/30
************************************/
#include <stdio.h>
#define MAX_N 20

void initArray(int *arr, int len);

int main(void) {
	int state[MAX_N], amp[MAX_N];
	int n, m, c, i, target, max, now, times;
	
	times = 0;
	while (scanf("%d %d %d", &n, &m, &c) == 3) {
		/* 測試結束 */
		if (n == 0 && m == 0 && c == 0)
			break;
		/* 初始化各項資料 */
		initArray(state, MAX_N);
		initArray(amp, MAX_N);
		max = 0;
		now = 0;
		
		for (i = 0; i < n; i++)
			scanf("%d", &amp[i]);
		
		for (i = 0; i < m; i++) {
			scanf("%d", &target);
			target--; /* for array index */
			/* 如果電器是關的 */
			if (state[target] == 0) {
				now += amp[target];
				state[target] = 1;
				/* 檢查最大值 */
				if (now > max)
					max = now;
			} else {
				now -= amp[target];
				state[target] = 0;
			}
		}
		times++;
		
		/* 印出結果 */
		printf("Sequence %d\n", times);
		if (max > c) {
			printf("Fuse was blown.\n");
		} else {
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", max);
		}
		printf("\n");
	}
	
	return 0;
}

void initArray(int *arr, int len) {
	int i;
	
	for (i = 0; i < len; i++) {
		arr[i] = 0;
	}
}