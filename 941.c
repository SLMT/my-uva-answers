/************************************
	Problem ID: UVa 941
	Programmer: SLMT
	Last Revised Date: 2012/12/4
************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

int compare(const void *a, const void *b);

int main(void) {
	int i, j, k, n, f, len, tmp, pos[MAX];
	long long q, t, factorial[MAX];
	char str[MAX + 1];
	
	/* 先把 20! 之前的解都記錄下來 */
	factorial[0] = 1;
	for (i = 1; i < MAX; i++)
		factorial[i] = factorial[i-1] * (i + 1);
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		/* 讀取 input */
		scanf("%s", str);
		scanf("%lld", &t);
		
		/* 初始化位置表 */
		len = strlen(str);
		for (j = 0; j < len; j++)
			pos[j] = j;
			
		/* 依照 t 來排列位置表 */
		for (j = 0; j < len - 1; j++) {
			f = len - 1 - j;
			q = t / factorial[f-1]; /* 要移到目前 j 位的相對 pos */
			t = t % factorial[f-1]; /* 更新 t */
			/* 用類似 insertion sort 的方式把數字慢慢往前移 */
			for (k = q + j; k > j; k--) {
				tmp = pos[k];
				pos[k] = pos[k-1];
				pos[k-1] = tmp;
			}
		}
		
		/* sort 字串 */
		qsort((void *)str, len, sizeof(str[0]), compare);
		/* 依照位置表輸出 */
		for (j = 0; j < len; j++)
			printf("%c", str[pos[j]]);
		printf("\n");
	}
	
	return 0;
}

/* for qsort */
int compare(const void *a, const void *b)
{
	char c = *(char *)a;
	char d = *(char *)b;
	if(c < d)
		return -1;
	else if (c == d)
		return 0;
	else
		return 1;
}