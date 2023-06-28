/************************************
	Problem ID: UVa 537, TPC 7429
	Programmer: SLMT
	Last Revised Date: 2013/2/27
************************************/
#include <stdio.h>

double parsePrefix(int ch) {
	switch (ch) {
		case 'm':
			return 0.001;
		case 'k':
			return 1000.0;
		case 'M':
			return 1000000.0;
		default:
			return 1.0;
	}
}

int main(void) {
	int T, times;
	double P, U, I, mul;
	int lastCh, ch;
	
	scanf("%d", &T);
	for (times = 1; times <= T; times++) {
		printf("Problem #%d\n", times);
		P = -1.0;
		U = -1.0;
		I = -1.0;
		/* 抓取所需資訊 */
		lastCh = fgetc(stdin);
		while ((ch = fgetc(stdin)) != '\n') {
			if (ch == '=') {
				switch (lastCh) {
					case 'P':
						scanf("%lf", &P);
						ch = fgetc(stdin);
						mul = parsePrefix(ch);
						P = P * mul;
						break;
					case 'U':
						scanf("%lf", &U);
						ch = fgetc(stdin);
						mul = parsePrefix(ch);
						U = U * mul;
						break;
					case 'I':
						scanf("%lf", &I);
						ch = fgetc(stdin);
						mul = parsePrefix(ch);
						I = I * mul;
						break;
				}
			}
			lastCh = ch;
		}
		if (P < 0)
			printf("P=%.2lfW\n\n", I * U);
		else if (U < 0)
			printf("U=%.2lfV\n\n", P / I);
		else
			printf("I=%.2lfA\n\n", P / U);
	}
	
	return 0;
}