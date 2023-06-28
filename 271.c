/************************************
	Problem ID: UVa 271, TPC 7201 - Simply Syntax 
	Programmer: SLMT
	Last Revised Date: 2013/3/28
************************************/
#include <stdio.h>
#define STACK_MAX 300

int inPZ(int ch);
int isCDEI(int ch);

int main(void) {
	int size;
	char ch, stack[STACK_MAX];
	
	/* init */
	size = 0;
	while ((ch = getc(stdin)) != EOF) {
		if (ch == '\n') {
			/* output */
			if (size == 1 && inPZ(stack[0]))
				printf("YES\n");
			else
				printf("NO\n");
			/* init */
			size = 0;
		} else {
			stack[size++] = ch; /* push */
			/* check stack */
			while (inPZ(stack[size - 1]) && size > 1) {
				if (stack[size - 2] == 'N') { /* check 'N(s)' */
					size -= 2; /* pop twice */
					stack[size++] = 's'; /* push a word to represent the 'sentense' */
				} else if (inPZ(stack[size - 2]) && size > 2) { /* check '(C)ss' */
					if (isCDEI(stack[size - 3])) {
						size -= 3; /* pop three times */
						stack[size++] = 's'; /* push a word to represent the 'sentense' */
					} else
						break;
				} else
					break;
			}
		}
	}
	
	return 0;
}

int inPZ(int ch) {
	return (ch >= 'p' && ch <= 'z');
}

int isCDEI(int ch) {
	return (ch == 'C' || ch == 'D' || ch == 'E' || ch == 'I');
}