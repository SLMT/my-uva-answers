/************************************
	Problem ID: UVa 441, TPC 7222 - Lotto 
	Programmer: SLMT
	Last Revised Date: 2013/4/3
************************************/
#include <cstdio>
#include <vector>

using namespace std;

vector<int> nums;

void DFS(int start, int end, int count, vector<int> seq);

int main(void) {
	int n, num;
	bool first = true; // 測資間空行處理
	
	while (scanf("%d", &n) == 1) {
		if (n == 0)
			break;
		
		if (first)
			first = false;
		else
			printf("\n");
		
		// read numbers
		nums.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &num);
			nums.push_back(num);
		}
		
		// DFS print
		vector<int> empty;
		DFS(0, n-1, 6, empty);
	}
	
	return 0;
}

void DFS(int start, int end, int count, vector<int> seq) {
	if (count == 0) {
		vector<int>::iterator it = seq.begin();
		printf("%d", *it);
		it++;
		while (it != seq.end()) {
			printf(" %d", *it);
			it++;
		}
		printf("\n");
	} else
		for (int i = start; i < end - count + 2; i++) {
			vector<int> newSeq = seq;
			newSeq.push_back(nums[i]);
			DFS(i+1, end, count-1, newSeq);
		}
}