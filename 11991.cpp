/************************************
	Problem ID: UVa 11991, TPC 7207 - Easy Problem from Rujia Liu?
	Programmer: SLMT
	Last Revised Date: 2013/4/15
************************************/
#include <cstdio>
#include <algorithm>
#define SIZE_MAX 100010

using namespace std;

typedef struct data_t {
	int num, index, order;
} Data;

Data nums[SIZE_MAX];

bool compareByNum(Data a, Data b);
int binarySearch(int start, int end, int num, int order);

int main(void) {
	int n, m, k, v;
	int now, count;
	
	while (scanf("%d %d", &n, &m) == 2) {
		// read input
		for (int i = 0; i < n; i++) {
			scanf("%d", &(nums[i].num));
			nums[i].index = i;
		}
		// sort
		stable_sort(nums, nums + n, compareByNum);
		// check order
		now = -1; // 注意：這題的數字都是正整數
		count = 0;
		for (int i = 0; i < n; i++) {
			if (now != nums[i].num) {
				now = nums[i].num;
				count = 0;
			}
			nums[i].order = count++;
		}
		// read query
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &k, &v);
			// 注意第 k 個與 nums 的 index 不同
			printf("%d\n", binarySearch(0, n - 1, v, k - 1) + 1);
		}
	}
	
	return 0;
}

bool compareByNum(Data a, Data b) {
	return a.num < b.num;
}

int binarySearch(int start, int end, int num, int order) {
	if (start > end)
		return -1;
	int middle = (start + end) / 2;
	if (nums[middle].num == num && nums[middle].order == order)
		return nums[middle].index;
	else if ((nums[middle].num == num && nums[middle].order > order) ||
		(nums[middle].num > num))
		return binarySearch(start, middle - 1, num, order);
	else
		return binarySearch(middle + 1, end, num, order);
}