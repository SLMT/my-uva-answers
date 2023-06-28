/************************************
	Problem ID: UVa 12060, TPC 7500
	Programmer: SLMT
	Last Revised Date: 2013/3/13
************************************/
#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int countLen(int num) {
	if (num != 0) {
		int count = 1;
		while (num /= 10)
			count++;
		return count;
	} else
		return 0;
}

int main(void) {
	int i, n, a, b, c, g, in, sum, len_bc, len_a, temp, neg;
	int count = 1;
	char spaces[] = "                               ";
	char lines[] = "--------------------------------";
	
	while (scanf("%d", &n) == 1) {
		if (n == 0)
			break;
		sum = 0;
		neg = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &in);
			sum += in;
		}
		/* check negtive */
		if (sum < 0) {
			sum = -sum;
			neg = 1;
		}
		/* count a, b, c */
		a = sum / n;
		b = sum % n;
		c = n;
		/* refine b, c */
		g = gcd(b, c);
		b /= g;
		c /= g;
		/* count the length of number */
		len_bc = countLen(b);
		temp = countLen(c);
		if (temp > len_bc)
			len_bc = temp;
		len_a = countLen(a);
		/* output */
		printf("Case %d:\n", count++);
		
		if (neg == 1) {
			if (b != 0) {
				printf("  %.*s%*d\n", len_a, spaces, len_bc, b);
				if (a != 0)
					printf("- %d%.*s\n", a, len_bc, lines);
				else
					printf("- %.*s\n", len_bc, lines);
				printf("  %.*s%*d\n", len_a, spaces, len_bc, c);
			} else
				printf("- %d\n", a);
		} else {
			if (b != 0) {
				printf("%.*s%*d\n", len_a, spaces, len_bc, b);
				if (a != 0)
					printf("%d%.*s\n", a, len_bc, lines);
				else
					printf("%.*s\n", len_bc, lines);
				printf("%.*s%*d\n", len_a, spaces, len_bc, c);
			} else
				printf("%d\n", a);
		}
	}
	
	return 0;
}