/************************************
	Problem ID: UVa 532, TPC 7203 - Dungeon Master 
	Programmer: SLMT
	Last Revised Date: 2013/3/28
************************************/
#include <stdio.h>
#define MAX 35
#define QUEUE_MAX 10000

typedef enum e_status {UNDISCOVER, DISCOVER, WALL} Stat;
typedef struct pos_t {
	int x, y, z;
} Position;

Stat map[MAX][MAX][MAX];
int dis[MAX][MAX][MAX];

Position queue[QUEUE_MAX];
int head, tail, size;

void resetQueue();
void enqueue(Position p);
Position dequeue();
int empty();

int main(void) {
	int l, h, w;
	int i, j, k;
	int direction[6][3] = {{0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
	Position start, end, now, side;
	char ch;
	
	while (scanf("%d %d %d", &l, &h, &w) == 3) {
		if (l + h + w == 0)
			break;
		/* read input */
		for (i = 0; i < l; i++)
			for (j = 0; j < h; j++)
				for (k = 0; k < w; k++) {
					while ((ch = getc(stdin)) == '\n'); /* read ch but not \n */
					switch (ch) {
						case 'S':
							map[i][j][k] = UNDISCOVER;
							start.x = i;
							start.y = j;
							start.z = k;
							break;
						case '.':
							map[i][j][k] = UNDISCOVER;
							break;
						case '#':
							map[i][j][k] = WALL;
							break;
						case 'E':
							map[i][j][k] = UNDISCOVER;
							end.x = i;
							end.y = j;
							end.z = k;
							break;
					}
				}
		/* BFS */
		/* 把距離都設為 -1(到不了) */
		for (i = 0; i < l; i++)
			for (j = 0; j < h; j++)
				for (k = 0; k < w; k++)
					dis[i][j][k] = -1;
		map[start.x][start.y][start.z] = DISCOVER;
		dis[start.x][start.y][start.z] = 0;
		resetQueue();
		enqueue(start);
		while (!empty()) {
			now = dequeue();
			for (i = 0; i < 6; i++) {
				/* 找出 now 旁邊的點 */
				side.x = now.x + direction[i][0];
				side.y = now.y + direction[i][1];
				side.z = now.z + direction[i][2];
				/* 如果點還沒被看過 */
				if (side.x >= 0 && side.x < l && side.y >= 0 && side.y < h && side.z >= 0 && side.z < w) {/* 要先確定在邊界內 */
					if (map[side.x][side.y][side.z] == UNDISCOVER) {
						map[side.x][side.y][side.z] = DISCOVER;
						dis[side.x][side.y][side.z] = dis[now.x][now.y][now.z] + 1;
						enqueue(side);
					}
				}
			}
		}
		/* output */
		if (dis[end.x][end.y][end.z] == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", dis[end.x][end.y][end.z]);
	}
	
	return 0;
}

void resetQueue() {
	head = 0;
	tail = 0;
	size = 0;
}

void enqueue(Position p) {
	queue[tail] = p;
	tail = (tail + 1) % QUEUE_MAX;
	size++;
}

Position dequeue() {
	Position temp;
	temp = queue[head];
	head = (head + 1) % QUEUE_MAX;
	size--;
	return temp;
}

int empty() {
	return size == 0;
}