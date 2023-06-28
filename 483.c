/************************************
	Problem ID: UVa 483, TPC 7499
	Programmer: SLMT
	Last Revised Date: 2013/3/1
************************************/
#include <stdio.h>
#define MAX 10000

int main(void) {
	int ch, word[MAX], index = 0;
	
	while ((ch = getc(stdin)) != EOF) {
		if (ch == '\n' || ch == ' ') {
			while (index > 0)
				printf("%c", word[--index]);
			printf("%c", ch);
		} else
			word[index++] = ch;
	}

	return 0;
}