/************************************
	Problem ID: UVa 10954, TPC 7541 - Add All 
	Programmer: SLMT
	Last Revised Date: 2013/4/20
************************************/
#include <stdio.h>
#define HEAP_MAX 5010

int heap[HEAP_MAX], heapSize;

void reset(void);
void push(int number);
int pop(void);
int top(void);
void swap(int *a, int *b);

int main(void) {
	int n, num, a, b, sum, cost;
	int i;
	
	while (scanf("%d", &n) == 1) {
		if (n == 0)
			break;
		
		/* read input */
		reset();
		for (i = 0; i < n; i++) {
			scanf("%d", &num);
			push(num);
		}
		/* Greedy */
		cost = 0;
		while (heapSize >= 2) {
			a = pop();
			b = pop();
			sum = a + b;
			cost += sum;
			push(sum);
		}
		/* output */
		printf("%d\n", cost);
	}
	
	return 0;
}

void reset(void) {
	heapSize = 0;
}

void push(int number) {
	int now, parent;
	heapSize++;
	heap[heapSize] = number;
	
	/* 從最底層往上換 */
	now = heapSize;
	parent = heapSize / 2;
	while (parent > 0 && heap[now] < heap[parent]) {
		swap(&heap[now], &heap[parent]);
		now = parent;
		parent = now / 2;
	}
}

int pop(void) {
	int output = heap[1]; /* top */
	int now, leftChild, rightChild;
	heap[1] = heap[heapSize];
	heapSize--;
	
	/* 從頂層往下換 */
	now = 1;
	leftChild = 2;
	rightChild = 3;
	while (leftChild <= heapSize) {
		if (rightChild <= heapSize && heap[leftChild] > heap[rightChild] &&
			heap[now] > heap[rightChild]) {
			swap(&heap[now], &heap[rightChild]);
			now = rightChild;
		} else if (heap[now] > heap[leftChild]) {
			swap(&heap[now], &heap[leftChild]);
			now = leftChild;
		} else
			break;
		leftChild = now * 2;
		rightChild = now * 2 + 1;
	}
	
	return output;
}

int top(void) {
	return heap[1];
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}