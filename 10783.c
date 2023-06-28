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
		/* 璸衡计计 */
		/* 猔種2~8 籔 3~7 计计琌 */
		if (!(a & 1))
			a++;
		if (!(b & 1))
			b--;
		num = (b - a)/2 + 1;
		
			
		/* 辫そΑ */
		ans = (a + b) * num / 2;
		
		printf("Case %d: %d\n", times, ans);
	}
	
	return 0;
}