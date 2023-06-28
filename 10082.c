/************************************
	Problem ID: UVa 10082
	Programmer: SLMT
	Last Revised Date: 2012/12/5
************************************/
#include <stdio.h>

char map[49] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int search(char ch);

int main(void) {
	char ch;

	while ((ch = fgetc(stdin)) != EOF) {
		if (ch == '\n' || ch == ' ')
			printf("%c", ch);
		else
			printf("%c", map[search(ch) - 1]);
	}
	
	return 0;
}

int search(char ch) {
	int i;
	for (i = 0; i < 48; i++)
		if (map[i] == ch)
			return i;
}