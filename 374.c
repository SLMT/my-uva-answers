/************************************
	Problem ID: UVa 374, TPC 7079
	Programmer: SLMT
	Last Revised Date: 2013/3/7
************************************/
#include <stdio.h>
#define POWER_MAX 50

int main(void) {
	int B, P, M, Ans;
	int i, maxPower, powerBin[POWER_MAX], exMod[POWER_MAX];
	
	while (scanf("%d %d %d", &B, &P, &M) == 3) {
		/* parse power to binary */
		maxPower = 0;
		while (P > 0) {
			if (P % 2)
				powerBin[maxPower++] = 1;
			else
				powerBin[maxPower++] = 0;
			P >>= 1; /* P/2 */
		}
		/* create table */
		exMod[0] = B % M;
		for (i = 1; i < maxPower; i++)
			exMod[i] = (exMod[i - 1] * exMod[i - 1]) % M;
		/* calculate result */
		Ans = 1;
		for (i = 0; i < maxPower; i++)
			if (powerBin[i] == 1)
				Ans = (Ans * exMod[i]) % M;
		printf("%d\n", Ans);
	}

	return 0;
}