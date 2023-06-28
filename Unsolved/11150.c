/************************************
	Problem ID: UVa 11150
	Programmer: SLMT
	Last Revised Date: 2012/12/12
************************************/
#include <stdio.h>

int main(void) {
	int n, now, empty, sum, max, borrow;
	
	while (scanf("%d", &n) == 1) {
		max = 0;
		/* 分別測試沒有借、借 1 或 2 瓶的結果 */
		for (borrow = 0; borrow < 3; borrow++) {
			sum = n; /* 先給他喝個 n 瓶 */
			empty = n + borrow;
			/* 開始模擬 */
			while (empty >= 3) {
				/* 換瓶子 */
				now = empty / 3;
				empty = empty % 3;
				/* 喝可樂 */
				sum += now;
				empty += now;
			}
			/* 看看剩下夠不夠還，而且是不是最多的一次 */
			if (empty >= borrow && sum > max)
				max = sum;
		}
		printf("%d\n", max);
	}
	
	return 0;
}