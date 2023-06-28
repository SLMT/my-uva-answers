/************************************
	Problem ID: UVa 10141
	Programmer: SLMT
	Last Revised Date: 2012/12/6
************************************/
#include <stdio.h>
#include <string.h>
#define STR_MAX 100

void readString(char* target);

int main(void) {
	int n, p, r, best_r;
	double d, best_d;
	int i, j, times;
	char tmp[STR_MAX], comp[STR_MAX], bestComp[STR_MAX];
	
	times = 0;
	while (scanf("%d %d", &n, &p) == 2) {
		if (n == 0 && p == 0)
			break;
		
		/* 略過 n 行資料清單 */
		for (i = 0; i < n; i++)
			readString(tmp);
			
		best_r = 0;
		best_d = 0.0;
		/* 讀取廠商資料 */
		for (i = 0; i < p; i++) {
			/* 讀取廠商名稱與金額、選項數目等 */
			readString(comp);
			scanf("%lf %d", &d, &r);
			/* 看看是不是目前為止最佳選擇 */
			if (r > best_r) {
				best_r = r;
				best_d = d;
				strcpy(bestComp, comp);
			} else if (r == best_r && d < best_r) {
				best_r = r;
				best_d = d;
				strcpy(bestComp, comp);
			}
			/* 略過 r 行清單 */
			for (j = 0; j < r; j++)
				readString(tmp);
		}
		
		/* 輸出結果 */
		times++;
		if (times != 1)
			printf("\n");
		printf("RFP #%d\n", times);
		printf("%s\n", bestComp);
	}
	
	return 0;
}

void readString(char* target) {
	char ch;
	int i = 0;
	
	while ((ch = fgetc(stdin)) != '\n' || i == 0) {
		if (ch != '\n') {
			target[i] = ch;
			i++;
		}
	}
	target[i] = '\0';
}