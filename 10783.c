/************************************
	Problem ID: UVa 10783, TPC 7070
	Programmer: SLMT
	Last Revised Date: 2013/2/20
************************************/
#include <stdio.h>

int main(void) {
	int T, a, b, num, ans, times;
	
	scanf("%d", &T);
	for (times = 1; times <= T; times++) {
		scanf("%d %d", &a, &b);
		/* �p��_�ƭӼ� */
		/* �`�N�G2~8 �P 3~7 ���_�ƭӼƬO�ۦP�� */
		if (!(a & 1))
			a++;
		if (!(b & 1))
			b--;
		num = (b - a)/2 + 1;
		
			
		/* ��Τ��� */
		ans = (a + b) * num / 2;
		
		printf("Case %d: %d\n", times, ans);
	}
	
	return 0;
}