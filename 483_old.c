/************************************
	Problem ID: UVa 483
	Programmer: SLMT
	Last Revised Date: 2012/11/30
************************************/
#include <stdio.h>
#define STR_MAX 100

int main(void) {
	char ch, str[STR_MAX];
	int pointer = 0;
	
	while ((ch = fgetc(stdin)) != EOF) {
		if (ch == '\n') {
			/* 輸出字串 */
			do {
				pointer--;
				printf("%c", str[pointer]);
			} while (pointer != 0);
			printf("\n");
		} else if (ch == ' ') {
			/* 輸出字串 */
			do {
				pointer--;
				printf("%c", str[pointer]);
			} while (pointer != 0);
			printf(" ");
		} else {
			/* 記錄一個字元 */
			str[pointer] = ch;
			pointer++;
		}
	}
	
	return 0;
}