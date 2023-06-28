/************************************
	Problem ID: UVa 834, TPC 7083
	Programmer: SLMT
	Last Revised Date: 2013/3/
************************************/
#include <stdio.h>

int main(void) {
	int up, down, nextDown;
	
	while (scanf("%d %d", &up, &down) == 2) {
		printf("[%d;", up / down);
		nextDown = up % down;
		while (nextDown != 1) {
			up = down;
			down = nextDown;
			printf("%d,", up / down);
			nextDown = up % down;
		}
		printf("%d]\n", down);
	}
	
	return 0;
}