/************************************
	Problem ID: UVa 739
	Programmer: SLMT
	Last Revised Date: 2012/12/1
************************************/
#include <stdio.h>
#define CODE_MAX 4
#define NAME_NUM 30

char getCode(char ch);

int main(void) {
	char ch, code, name[NAME_NUM], output[CODE_MAX + 1], lastCode = ' ';
	int index = 0;
	int nameIndex = 0;
	
	printf("         NAME                     SOUNDEX CODE\n");
	while ((ch = fgetc(stdin)) != EOF) {
		if (ch != '\n') {
			/* 紀錄名字 */
			name[nameIndex++] = ch;
			/* 第一個字元 */
			if (index == 0) {
				output[index++] = ch;
				lastCode = getCode(ch);
			} else if (index < 4) {
				/* 之後的字元 */
				code = getCode(ch);
				if (code != '0' && code != lastCode)
					output[index++] = code;
				lastCode = code;
			}
		} else {
			while (index < CODE_MAX)
				output[index++] = '0';
			output[CODE_MAX] = '\0';
			name[nameIndex] = '\0';
			/* 輸出結果，重設變數 */
			index = 0;
			nameIndex = 0;
			lastCode = ' ';
			printf("         %-25s%s\n", name, output);
		}
	}
	printf("                   END OF OUTPUT\n");
	
	return 0;
}

char getCode(char ch) {
	if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y' || ch == 'W' || ch == 'H')
		return '0';
	else if (ch == 'B' || ch == 'P' || ch == 'F' || ch == 'V')
		return '1';
	else if (ch == 'C' || ch == 'S' || ch == 'K' || ch == 'G' || ch == 'J' || ch == 'Q' || ch == 'X' || ch == 'Z')
		return '2';
	else if (ch == 'D' || ch == 'T')
		return '3';
	else if (ch == 'L')
		return '4';
	else if (ch == 'M' || ch == 'N')
		return '5';
	else
		return '6';
}