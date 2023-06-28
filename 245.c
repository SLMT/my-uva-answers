/************************************
	Problem ID: UVa 245, TPC 7089
	Programmer: SLMT
	Last Revised Date: 2013/3/17
************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STR_MAX 100

typedef struct node_t {
	char word[STR_MAX];
	struct node_t *pre;
	struct node_t *next;
} Node;

Node *head, *tail;

void insert(char *input);
Node* search(int target);
void moveToHead(Node *node);

int main(void) {
	int ch, lastCh, count = 0;
	int type; /* 1: alpha, 2: digit */
	char str[STR_MAX];
	Node *node;

	head = NULL;
	tail = NULL;
		
	while ((ch = getc(stdin)) != EOF) {
		/* 終止條件 */
		if (lastCh == '\n' && ch == '0')
			break;
		
		/* 處理 input */
		if (isalpha(ch)) {
			type = 1;
			str[count++] = ch;
		} else if (isdigit(ch)) {
			type = 2;
			str[count++] = ch;
		} else {
			if (count != 0) {
				str[count] = '\0';
				if (type == 1) {
					insert(str);
					printf("%s", str);
				} else if (type == 2) {
					node = search(atol(str));
					printf("%s", node->word);
					moveToHead(node);
				}
				count = 0;
			}
			printf("%c", ch);
		}
		/* 紀錄上一個字 */
		lastCh = ch;
	}
	
	return 0;
}

void insert(char *str) {
	Node *new;
	
	/* create node */
	new = (Node *)malloc(sizeof(Node));
	strcpy(new->word, str);
	new->pre = NULL;
	new->next = NULL;
	
	/* insert node */
	if (head == NULL) {
		head = new;
		tail = new;
	} else {
		head->pre = new;
		new->next = head;
		head = new;
	}
}

Node* search(int target) {
	Node *current;
	int pos;
	for (current = head, pos = 1; current != NULL; current = current->next, pos++)
		if (pos == target)
			return current;
	return NULL;
}

/* head 不可能為 NULL */
void moveToHead(Node *node) {
	if (node != head) {
		/* 先把 node 前後接起來 */
		node->pre->next = node->next;
		if (node != tail)
			node->next->pre = node->pre;
		else /* 注意 node 是 tail 的情形 */
			tail = node->pre;
		/* 把 node 移到 head */
		node->pre = NULL;
		node->next = head;
		head->pre = node;
		head = node;
	}
}
