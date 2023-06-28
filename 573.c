/************************************
	Problem ID: UVa 573
	Programmer: SLMT
	Last Revised Date: 2012/11/30
************************************/
#include <stdio.h>

int main(void) {
	int day;
	double H, U, D, F, nowH, rate;
	
	while (scanf("%lf %lf %lf %lf", &H, &U, &D, &F) == 4) {
		if (H == 0)
			break;
		
		nowH = 0;
		rate = 100;
		day = 1;
		while (1) {
			nowH += U * (rate / 100);
			/* �ˬd�O�_�F��ؼ� */
			if (nowH > H) {
				printf("success on day %d\n", day);
				break;
			}
			/* �����𮧡A���U�� */
			nowH -= D;
			
			/* ��s rate */
			if (rate <= F)
				rate = 0;
			else
				rate -= F;
			
			/* �ˬd���\�Υ��� */
			if (nowH < 0) {
				printf("failure on day %d\n", day);
				break;
			}
			
			/* �U�@�� */
			day++;
		}
	}
	
	return 0;
}