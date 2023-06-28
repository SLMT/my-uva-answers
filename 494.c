/************************************
	Problem ID: UVa 494, TPC 7073
	Programmer: SLMT
	Last Revised Date: 2013/2/20
************************************/
#include <stdio.h>
#include <ctype.h>

int main(void) {
	int ch, continues, count = 0;
	
	while ((ch = fgetc(stdin)) != EOF) {
		if (ch == '\n') { /* 換行 */
			continues = 0;
			printf("%d\n", count);
			count = 0;
		} else if (isalpha(ch)) { /* 英文字母 */
			continues = 1;
		} else { /* 其他字元(包括空白) */
			if (continues == 1)
				count++;
			continues = 0;
		}
	}
	
	return 0;
}