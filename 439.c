/************************************
	Problem ID: UVa 439, TPC 7205 - Knight Moves 
	Programmer: SLMT
	Last Revised Date: 2013/3/30
************************************/
#include <stdio.h>
#define WIDTH 8
#define QUEUE_MAX 50

typedef struct pos_t {
	int x, y;
} Position;

typedef enum status_e { UNDISCOVER, DISCOVER } Status;

Position queue[QUEUE_MAX];
int head, tail;

void reset();
void enqueue(Position p);
Position dequeue();
int empty();

int main(void) {
	Position start, end, now, next;
	Status map[WIDTH][WIDTH];
	char ch;
	int i, j, finish, dis[WIDTH][WIDTH];
	int nextStep[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
	
	while ((ch = getc(stdin)) != EOF) {
		/* read input */
		start.x = ch - 'a';
		ch = getc(stdin);
		start.y = ch - '1';
		getc(stdin); /* read ' ' */
		ch = getc(stdin);
		end.x = ch - 'a';
		ch = getc(stdin);
		end.y = ch - '1';
		getc(stdin); /* read '\n' */
		/* init BFS */
		for (i = 0; i < WIDTH; i++)
			for (j = 0; j < WIDTH; j++) {
				map[i][j] = UNDISCOVER;
				dis[i][j] = -1;
			}
		finish = 0;
		/* begin with start point */
		map[start.x][start.y] = DISCOVER;
		dis[start.x][start.y] = 0;
		reset();
		enqueue(start);
		while (!empty() && !finish && (start.x != end.x || start.y != end.y)) {
			now = dequeue();
			/* for all next step */
			for (i = 0; i < 8; i++) {
				next.x = now.x + nextStep[i][0];
				next.y = now.y + nextStep[i][1];
				if (next.x >= 0 && next.x < 8 && next.y >= 0 && next.y < 8) {
					if (map[next.x][next.y] == UNDISCOVER) {
						map[next.x][next.y] = DISCOVER;
						dis[next.x][next.y] = dis[now.x][now.y] + 1;
						if (next.x == end.x && next.y == end.y) {
							finish = 1;
							break;
						}
						enqueue(next);
					}
				}
			}
		}
		/* output result */
		printf("To get from %c%d to %c%d takes %d knight moves.\n",
			start.x + 'a', start.y + 1, end.x + 'a', end.y + 1, dis[end.x][end.y]);
	}
	
	return 0;
}

void reset() {
	head = 0;
	tail = 0;
}

void enqueue(Position p) {
	queue[tail++] = p;
}

Position dequeue() {
	return queue[head++];
}

int empty() {
	if (head == tail)
		return 1;
	return 0;
}