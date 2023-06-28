/************************************
	Problem ID: UVa 514, TPC 7200 - Rails 
	Programmer: SLMT
	Last Revised Date: 2013/3/30
************************************/
#include <stdio.h>
#define STACK_MAX 1010

int main(void) {
	int N, target, waitHead, yes; /* waitHead: 代表目前還沒進入 stack 正在等待的第一號 */
	int i, j;
	int top, stack[STACK_MAX];
	
	while (scanf("%d", &N) == 1) {
		if (N == 0)
			break;
		/* test case loop */
		target = 1;
		while (target) {
			/* init */
			yes = 1;
			waitHead = 1;
			top = -1;
			/* read test case */
			for (i = 0; i < N; i++) {
				scanf("%d", &target);
				if (target == 0)
					break;
				
				/* use stack to simulate */
				if (yes) {
					if (waitHead == target) /* 排隊的車頭就是目標 => 直接進站再出來 */
						waitHead++;
					else if (waitHead < target) { /* 目標在排隊的對列裡面 => 把之前的車都塞進 stack */
						/* push waitHead ~ target - 1 */
						for (j = waitHead; j < target; j++)
							stack[++top] = j;
						waitHead = target + 1;
					} else { /* 目標不在排隊的對列內 */
						if (stack[top] == target)
							top--; /* pop */
						else
							yes = 0; /* 不在 stack top 的話就不可能出的來 */
					}
				}
			}
			/* output */
			if (target != 0) {
				if (yes)
					printf("Yes\n");
				else
					printf("No\n");
			}
		}
		printf("\n");
	}
	
	return 0;
}