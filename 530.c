/************************************
	Problem ID: UVa 530, TPC 7082
	Programmer: SLMT
	Last Revised Date: 2013/3/7
************************************/
#include <stdio.h>
#define F_MAX 18
typedef long long Long;

Long c(Long m, Long n);

int main(void) {
	Long m, n;
	int i;
	
	/* for input */
	/* Note: %I64d for Windows, %lld for others */
	while (scanf("%lld %lld", &m, &n) == 2) {
		if (m == 0 && n == 0)
			break;
		/* output */
		/* Note: %I64d for Windows, %lld for others */
		printf("%lld\n", c(m, n));
	}
	return 0;
}

Long c(Long m, Long n) {
	if (n > m/2)
		return c(m, m-n);
	
	/* 	count C
		m = 12, n = 5
		12 x 11 x 10 x 9 x 8 upper
		--------------------
		 5 x  4 x  3 x 2 x 1 lower
	*/
	Long longIndex, C = 1;
	for (longIndex = m; longIndex > m - n; longIndex--) {
		/* upper */
		C *= longIndex;
		/* lower */
		C /= m - longIndex + 1;
	}
	
	return C;
}