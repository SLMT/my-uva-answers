/************************************
	Problem ID: UVa 673, TPC 7202 - Parentheses Balance 
	Programmer: SLMT
	Last Revised Date: 2013/3/26
************************************/
#include <stdio.h>
#define MAX 200

char stack[MAX];
int pointer;

void reset();
void push(char ch);
char top();
char pop();
int size();

int main(void) {
	int i, index, len, N, yes;
	char ch;
	
	scanf("%d", &N);
	getc(stdin); /* read \n */
	for (i = 0; i < N; i++) {
		/* init */
		reset();
		yes = 1;
		/* read input */
		while ((ch = getc(stdin)) != '\n' && ch != EOF) {
			if (ch == '(' || ch == '[')
				push(ch);
			else if ((ch == ')' && top() == '(') || (ch == ']' && top() == '['))
				pop();
			else
				yes = 0;
		}
		/* output */
		if (yes && size() == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}

void reset() {
	pointer = 0;
}

void push(char ch) {
	stack[pointer++] = ch;
}

char top() {
	if (size() == 0)
		return ' ';
	else
		return stack[pointer - 1];
}

char pop() {
	return stack[--pointer];
}

int size() {
	return pointer;
}