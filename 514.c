/************************************
	Problem ID: UVa 514, TPC 7200 - Rails 
	Programmer: SLMT
	Last Revised Date: 2013/3/30
************************************/
#include <stdio.h>
#define STACK_MAX 1010

int main(void) {
	int N, target, waitHead, yes; /* waitHead: �N��ثe�٨S�i�J stack ���b���ݪ��Ĥ@�� */
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
					if (waitHead == target) /* �ƶ������Y�N�O�ؼ� => �����i���A�X�� */
						waitHead++;
					else if (waitHead < target) { /* �ؼЦb�ƶ�����C�̭� => �⤧�e��������i stack */
						/* push waitHead ~ target - 1 */
						for (j = waitHead; j < target; j++)
							stack[++top] = j;
						waitHead = target + 1;
					} else { /* �ؼФ��b�ƶ�����C�� */
						if (stack[top] == target)
							top--; /* pop */
						else
							yes = 0; /* ���b stack top ���ܴN���i��X���� */
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