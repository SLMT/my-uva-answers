/************************************
	Problem ID: UVa 202, TPC 7080
	Programmer: SLMT
	Last Revised Date: 2013/3/18
************************************/
#include <stdio.h>
#define MAX 3010

int main(void) {
	int x, y, temp, reminder[MAX], appear[MAX];
	int i, count, freq, start;
	
	while (scanf("%d %d", &x, &y) == 2) {
		/* init */
		for (i = 0; i < MAX; i++)
			appear[i] = 0;
		/* long division */
		count = 1;
		temp = x;
		reminder[0] = temp / y;
		temp %= y;
		while (appear[temp] == 0) {
			appear[temp] = count;
			temp *= 10;
			reminder[count++] = temp / y;
			temp %= y;
		}
		/* count frequency and reminder */
		start = appear[temp];
		freq = count - start;
		printf("%d/%d = %d.", x, y, reminder[0]);
		for (i = 1; i < count; i++) {
			if (i == start)
				printf("(");
			printf("%d", reminder[i]);
			if (i == start + 49) {
				printf("...)");
				break;
			} else if (i == count - 1)
				printf(")");
		}
		printf("\n   %d = number of digits in repeating cycle\n\n", freq);
	}
	
	return 0;
}