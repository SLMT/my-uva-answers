/************************************
	Problem ID: UVa 10062, TPC 7497
	Programmer: SLMT
	Last Revised Date: 2013/2/27
************************************/
#include <cstdio>
#include <algorithm>
#include <vector>
#define CODE_MAX 255

using namespace std;

typedef struct pair_t {
	int ch;
	int times;
} Pair;

void initPair(Pair *arr) {
	int i;
	for (i = 0; i < CODE_MAX; i++) {
		arr[i].ch = i;
		arr[i].times = 0;
	}
}

bool compare(Pair i, Pair j) {
	if (i.times < j.times)
		return true;
	else if (i.times == j.times && i.ch >= j.ch)
		return true;
	return false;
}

int main(void) {
	int ch, first;
	Pair pairs[CODE_MAX];
	
	initPair(pairs);
	first = 0;
	while ((ch = fgetc(stdin)) != EOF) {
		if (ch == '\n') {
			if (first)
				printf("\n");
			else
				first = 1;
			/* sort */
			vector<Pair> sorted(pairs, pairs + CODE_MAX);
			sort(sorted.begin(), sorted.end(), compare);
			/* 輸出結果 */
			for (unsigned i = 0; i < CODE_MAX; i++)
				if (sorted[i].times != 0)
					printf("%d %d\n", sorted[i].ch, sorted[i].times);
			/* 重設 times */
			initPair(pairs);
		} else
			pairs[ch].times++;
	}
	/* sort */
	vector<Pair> sorted(pairs, pairs + CODE_MAX);
	sort(sorted.begin(), sorted.end(), compare);
	/* 輸出結果 */
	for (unsigned i = 0; i < CODE_MAX; i++)
		if (sorted[i].times != 0)
			printf("%d %d\n", sorted[i].ch, sorted[i].times);
	
	return 0;
}