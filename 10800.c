/************************************
	Problem ID: UVa 10800, TPC 7496
	Programmer: SLMT
	Last Revised Date: 2013/2/27
************************************/
#include <stdio.h>
#define MAX 110
#define OFFSET(height) height + 50

int main(void) {
	int T, times, i, j;
	int graph[MAX][MAX] = {0};
	int ch, curH, maxH, minH, count, print;
	
	scanf("%d", &T);
	fgetc(stdin); /* eat '\n' */
	for (times = 1; times <= T; times++) {
		/* 初始化 */
		curH = 1;
		maxH = 0;
		minH = 1;
		count = 0;
		for (i = 0; i < MAX; i++)
			for (j = 0; j < MAX; j++)
				graph[i][j] = 0;
		/* 抓取資料並繪圖 */
		while ((ch = fgetc(stdin)) != '\n') {
			count++;
			switch (ch) {
				case 'R':
					if (curH > maxH)
						maxH = curH;
					graph[OFFSET(curH)][count] = 1;
					curH++;
					break;
				case 'C':
					if (curH > maxH)
						maxH = curH;
					graph[OFFSET(curH)][count] = 2;
					if (curH < minH)
						minH = curH;
					break;
				case 'F':
					curH--;
					graph[OFFSET(curH)][count] = 3;
					if (curH < minH)
						minH = curH;
					break;
			}
		}
		/* 輸出圖形 */
		printf("Case #%d:\n", times);
		for (i = maxH; i >= minH; i--) {
			printf("| ");
			/* 計算每行要印幾個字 */
			for (j = count; j >= 1; j--)
				if (graph[OFFSET(i)][j] != 0) {
					print = j;
					break;
				}
			/* 劃出走勢圖 */
			for (j = 1; j <= print; j++)
				switch (graph[OFFSET(i)][j]) {
					case 1:
						printf("/");
						break;
					case 2:
						printf("_");
						break;
					case 3:
						printf("\\");
						break;
					default:
						printf(" ");
				}
			printf("\n");
		}
		/* 輸出底線 */
		printf("+");
		for (i = 0; i < count + 2; i++)
			printf("-");
		printf("\n\n");
	}

	return 0;
}