/************************************
	Problem ID: UVa11371, TPC 7505
	Programmer: SLMT
	Last Revised Date: 2013/3/13
************************************/
#include <stdio.h>

int main(void) {
	int i, j, count[10];
	long long n, max, min;
	
	while (scanf("%lld", &n) == 1) {
		max = 0;
		min = 0;
		for (i = 0; i < 10; i++)
			count[i] = 0;
		/* �p�� n �����C�ӼƦr�X�{������ */
		while (n > 0) {
			count[n % 10]++;
			n /= 10;
		}
		/* �p��̤j�� */
		for (i = 9; i >= 0; i--)
			for (j = 0; j < count[i]; j++) {
				max *= 10;
				max += i;
			}
		/* �p��̤p�� */
		/* ����X�̰����(���i���s) */
		for (i = 1; i < 10; i++)
			if (count[i] != 0) {
				count[i]--;
				min = i;
				break;
			}
		/* �ɤW�Ѿl���Ʀr */
		for (i = 0; i < 10; i++) {
			for (j = 0; j < count[i]; j++) {
				min *= 10;
				min += i;
			}
		}
		/* ��X */
		printf("%lld - %lld = %lld = 9 * %lld\n", max, min, max - min, (max - min) / 9);
	}
	
	return 0;
}