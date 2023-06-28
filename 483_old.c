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
			/* ��X�r�� */
			do {
				pointer--;
				printf("%c", str[pointer]);
			} while (pointer != 0);
			printf("\n");
		} else if (ch == ' ') {
			/* ��X�r�� */
			do {
				pointer--;
				printf("%c", str[pointer]);
			} while (pointer != 0);
			printf(" ");
		} else {
			/* �O���@�Ӧr�� */
			str[pointer] = ch;
			pointer++;
		}
	}
	
	return 0;
}