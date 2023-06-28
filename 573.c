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
			/* 檢查是否達到目標 */
			if (nowH > H) {
				printf("success on day %d\n", day);
				break;
			}
			/* 蝸牛休息，往下滑 */
			nowH -= D;
			
			/* 更新 rate */
			if (rate <= F)
				rate = 0;
			else
				rate -= F;
			
			/* 檢查成功或失敗 */
			if (nowH < 0) {
				printf("failure on day %d\n", day);
				break;
			}
			
			/* 下一天 */
			day++;
		}
	}
	
	return 0;
}