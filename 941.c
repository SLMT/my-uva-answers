/************************************
	Problem ID: UVa 941
	Programmer: SLMT
	Last Revised Date: 2012/12/4
************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

int compare(const void *a, const void *b);

int main(void) {
	int i, j, k, n, f, len, tmp, pos[MAX];
	long long q, t, factorial[MAX];
	char str[MAX + 1];
	
	/* ���� 20! ���e���ѳ��O���U�� */
	factorial[0] = 1;
	for (i = 1; i < MAX; i++)
		factorial[i] = factorial[i-1] * (i + 1);
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		/* Ū�� input */
		scanf("%s", str);
		scanf("%lld", &t);
		
		/* ��l�Ʀ�m�� */
		len = strlen(str);
		for (j = 0; j < len; j++)
			pos[j] = j;
			
		/* �̷� t �ӱƦC��m�� */
		for (j = 0; j < len - 1; j++) {
			f = len - 1 - j;
			q = t / factorial[f-1]; /* �n����ثe j �쪺�۹� pos */
			t = t % factorial[f-1]; /* ��s t */
			/* ������ insertion sort ���覡��Ʀr�C�C���e�� */
			for (k = q + j; k > j; k--) {
				tmp = pos[k];
				pos[k] = pos[k-1];
				pos[k-1] = tmp;
			}
		}
		
		/* sort �r�� */
		qsort((void *)str, len, sizeof(str[0]), compare);
		/* �̷Ӧ�m���X */
		for (j = 0; j < len; j++)
			printf("%c", str[pos[j]]);
		printf("\n");
	}
	
	return 0;
}

/* for qsort */
int compare(const void *a, const void *b)
{
	char c = *(char *)a;
	char d = *(char *)b;
	if(c < d)
		return -1;
	else if (c == d)
		return 0;
	else
		return 1;
}