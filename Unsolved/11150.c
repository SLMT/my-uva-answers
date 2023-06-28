/************************************
	Problem ID: UVa 11150
	Programmer: SLMT
	Last Revised Date: 2012/12/12
************************************/
#include <stdio.h>

int main(void) {
	int n, now, empty, sum, max, borrow;
	
	while (scanf("%d", &n) == 1) {
		max = 0;
		/* ���O���ըS���ɡB�� 1 �� 2 �~�����G */
		for (borrow = 0; borrow < 3; borrow++) {
			sum = n; /* �����L�ܭ� n �~ */
			empty = n + borrow;
			/* �}�l���� */
			while (empty >= 3) {
				/* ���~�l */
				now = empty / 3;
				empty = empty % 3;
				/* �ܥi�� */
				sum += now;
				empty += now;
			}
			/* �ݬݳѤU�������١A�ӥB�O���O�̦h���@�� */
			if (empty >= borrow && sum > max)
				max = sum;
		}
		printf("%d\n", max);
	}
	
	return 0;
}