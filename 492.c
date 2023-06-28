/************************************
	Problem ID: UVa 492, TPC 7085
	Programmer: SLMT
	Last Revised Date: 2013/2/27
************************************/
#include <stdio.h>
#include <ctype.h>
#define STR_MAX 100000

int isVowel(int ch) {
	switch (tolower(ch)) {
		case 'a':
			return 1;
		case 'e':
			return 1;
		case 'i':
			return 1;
		case 'o':
			return 1;
		case 'u':
			return 1;
		default:
			return 0;
	}
}

int main(void) {
	int i, ch, tmp, count = 0;
	char str[STR_MAX];
	
	while (1) {
		ch = fgetc(stdin);
		if (isalpha(ch))
			str[count++] = ch;
		else {
			if (count > 0) {
				/* ³B²z Pig-Latin */
				if (isVowel(str[0]) == 0) {
					for (i = 1; i <= count - 1; i++)
						printf("%c", str[i]);
					printf("%cay", str[0]);
				} else {
					for (i = 0; i < count; i++)
						printf("%c", str[i]);
					printf("ay");
				}
				count = 0;
			}
			if (ch == EOF)
				break;
			printf("%c", ch);
		}
	}

	return 0;
}