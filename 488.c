/************************************
	Problem ID: UVa 488, TPC 7072
	Programmer: SLMT
	Last Revised Date: 2013/2/20
************************************/
#include <stdio.h>

int main(void) {
	int n, a, f, times, i, j, k;
	
	scanf("%d", &n);
	for (times = 0 ; times < n; times++) {
		scanf("%d %d", &a, &f);
		for (i = 0; i < f; i++) { /* �X�Ӫi */
			/* �L�X�W�b���򤤶� */
			for (j = 1; j <= a; j++) { /* �C�Ӫi�X�h */
				for (k = 1; k <= j; k++) /* �C�h�X�Ӧr */
					printf("%d", j);
				printf("\n");
			}
			/* �U�b�� */
			for (j = a - 1; j >= 0; j--) { /* �C�Ӫi�X�h */
				for (k = 1; k <= j; k++) /* �C�h�X�Ӧr */
					printf("%d", j);
				if (times == n - 1 && i == f - 1 && j == 0) /* ����b�̫�@�洫�� */
					;/* do nothing */
				else
					printf("\n");
			}
		}
	}
	
	return 0;
}