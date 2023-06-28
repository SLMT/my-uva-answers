/************************************
	Problem ID: UVa 540, TPC 7090
	Programmer: SLMT
	Last Revised Date: 2013/3/18
************************************/
#include <stdio.h>
#include <stdlib.h>
#define MEMBER_MAX 1000000
#define TEAM_MAX 1000

typedef struct node_t {
	int number;
	struct node_t *next;
} Node;

int team[MEMBER_MAX];

Node *head, *tail, *last[TEAM_MAX + 1];

void enqueue(int num);
void insertToTail(Node *new);
void insertToAfter(Node *target, Node *new);
int dequeue();
void freeQueue();

int main(void) {
	int i, j, T, n, member, teamNum, num, count = 1;
	char cmd[10];
	
	while (scanf("%d", &T) == 1) {
		if (T == 0)
			break;
		/* 初始化 taem 與 queue */
		head = NULL;
		tail = NULL;
		for (i = 0; i < MEMBER_MAX; i++)
			team[i] = 0;
		for (i = 0; i < TEAM_MAX; i++)
			last[i] = NULL;
		/* 載入 team 的成員資料 */
		for (teamNum = 1; teamNum <= T; teamNum++) {
			scanf("%d", &n);
			for (i = 0; i < n; i++) {
				scanf("%d", &member);
				team[member] = teamNum;
			}
		}
		/* 讀取指令 */
		printf("Scenario #%d\n", count++);
		while (scanf("%s", cmd) == 1) {
			if (cmd[0] == 'S')
				break;
			else if (cmd[0] == 'E') {
				scanf("%d", &num);
				enqueue(num);
			} else {
				num = dequeue();
				if (num != -1)
					printf("%d\n", num);
			}
		}
		/* 釋放 queue */
		freeQueue();
		printf("\n");
	}
	
	return 0;
}

void enqueue(int num) {
	Node *new, *teamLast;
	int teamNum;
	/* 建立一個新的 node */
	new = (Node *)malloc(sizeof(Node));
	new->number = num;
	new->next = NULL;
	
	/* 插入 queue 中 */
	teamNum = team[num];
	if (teamNum != 0) {
		/* 檢查 queue 中是否已經有同隊的成員 */
		if (last[teamNum] != NULL) {
			teamLast = last[teamNum];
			insertToAfter(teamLast, new);
		} else
			insertToTail(new);
		last[teamNum] = new;
	} else
		insertToTail(new);
}

/* 把 new 放進 queue 的尾巴 */
void insertToTail(Node *new) {
	if (head == NULL) {
		head = new;
		tail = new;
	} else {
		tail->next = new;
		tail = new;
	}
}

/* 把 new 插在某個 node 之後 */
void insertToAfter(Node *target, Node *new) {
	new->next = target->next;
	target->next = new;
	/* 檢查 target 是否在尾巴 */
	if (target == tail)
		tail = new;
}


int dequeue() {
	Node *temp;
	int num;
	if (head != NULL) {
		temp = head;
		head = temp->next;
		num = temp->number;
		/* 檢查 head 這個 element 是否為該隊最後一人 */
		if (temp == last[team[num]])
			last[team[num]] = NULL;
		free(temp);
		return num;
	}
	num = -1;
}

/* 釋放整個 queue 的記憶體空間 */
void freeQueue() {
	Node *current, *temp = NULL;
	for (current = head; current != NULL; current = current->next) {
		if (temp != NULL)
			free(temp);
		temp = current;
	}
	if (temp != NULL)
		free(temp);
}
