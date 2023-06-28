/************************************
	Problem ID: UVa 445, TPC 7498
	Programmer: SLMT
	Last Revised Date: 2013/3/1
************************************/
#include <stdio.h>
#include <ctype.h>

int main(void) {
	int ch, i, count = 0;
	
	while ((ch = getc(stdin)) != EOF) {
		if (isdigit(ch))
			count += ch - '0';
		else if (isalpha(ch) || ch == '*') {
			for (i = 0; i < count; i++)
				if (ch == 'b')
					printf(" ");
				else
					printf("%c", ch);
			count = 0;
		} else if (ch == '!' || ch == '\n')
			printf("\n");
	}
		
	return 0;
}