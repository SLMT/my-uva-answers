/************************************
	Problem ID: UVa 482, TPC 7078
	Programmer: SLMT
	Last Revised Date: 2013/3/6
************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N_MAX 1000
#define STR_MAX 100
#define BUFFER_SIZE 100000

int main(void) {
	int i, T, index[N_MAX], indexCount, strCount;
	char ch, s[N_MAX][STR_MAX], buffer[BUFFER_SIZE];
	
	scanf("%d", &T);
	while (T--) {
		indexCount = 0;
		strCount = 0;
		/* read Index */
		while (1) {
			ch = getc(stdin);
			if (isdigit(ch))
				buffer[strCount++] = ch;
			else {
				if (strCount != 0) {
					buffer[strCount] = '\0';
					strCount = 0;
					index[atoi(buffer) - 1] = indexCount++; /* parse */
				}
				if ((ch == '\n' && indexCount != 0) || ch == EOF)
					break;
			}
		}
		/* read Number */
		for (i = 0; i < indexCount; i++) {
			strCount = 0;
			while ((ch = fgetc(stdin)) != ' ' && ch != '\n' && ch != EOF)
				buffer[strCount++] = ch;
			buffer[strCount] = '\0';
			strcpy(s[i], buffer);
		}
		/* output */
		for (i = 0; i < indexCount; i++)
			printf("%s\n", s[index[i]]);
		if (T > 0)
			printf("\n");
	}
	
	return 0;
}