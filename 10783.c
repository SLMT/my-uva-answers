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
		/* 計算奇數個數 */
		/* 注意：2~8 與 3~7 的奇數個數是相同的 */
		if (!(a & 1))
			a++;
		if (!(b & 1))
			b--;
		num = (b - a)/2 + 1;
		
			
		/* 梯形公式 */
		ans = (a + b) * num / 2;
		
		printf("Case %d: %d\n", times, ans);
	}
	
	return 0;
}