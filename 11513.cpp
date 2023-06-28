/************************************
	Problem ID: UVa 11513, TPC 6007 - 9 Puzzle 
	Programmer: SLMT
	Last Revised Date: 2013/4/8
************************************/
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

// 記錄圖形狀態的資料結構
typedef struct status_t {
	int graph[3][3];
	int code; // 代表 graph 的索引
} Status;

queue<Status> wait;
void enqueue(Status num);
Status dequeue();
bool empty();

int encode(Status input);
Status move(Status ori, int row, int col);

int main(void) {
	map<int, bool> visited;
	map<int, int> dis, back, op; // dis: 距離, back: 上一點, op: 從上一點到這點移動的方法
	Status start, now, adj[6], input;
	int nowCode;
	
	// BFS 找出從原圖開始的所有可能性，並計算距離與紀錄上一點
	// 起點
	start.graph[0][0] = 1; start.graph[0][1] = 2; start.graph[0][2] = 3; 
	start.graph[1][0] = 4; start.graph[1][1] = 5; start.graph[1][2] = 6; 
	start.graph[2][0] = 7; start.graph[2][1] = 8; start.graph[2][2] = 9;
	start.code = encode(start); // 把圖形編碼成一串數字，作為索引
	// 紀錄起點資訊
	visited[start.code] = true;
	dis[start.code] = 0;
	back[start.code] = -1; // 代表不能再往前 trace
	op[start.code] = -1;
	enqueue(start);
	// 探索 Graph
	while (!empty()) {
		now = dequeue();
		// 找出這個圖形可能的變化
		for (int i = 0; i < 3; i++) // 左移所有列
			adj[i] = move(now, i, -1);
		for (int i = 0; i < 3; i++) // 下移所有行
			adj[i + 3] = move(now, -1, i);
		// 對於所有移動的可能
		for (int i = 0; i < 6; i++) {
			if (!visited[adj[i].code]) {
				visited[adj[i].code] = true; // 訪問過這個圖形
				dis[adj[i].code] = dis[now.code] + 1;
				back[adj[i].code] = now.code;
				op[adj[i].code] = i;
				enqueue(adj[i]);
			}
		}
	}
	// read input
	while (scanf("%d", &input.graph[0][0]) == 1) {
		if (input.graph[0][0] == 0)
			break;
		// read rest inputs
		scanf("%d %d %d %d %d %d %d %d", &input.graph[0][1], &input.graph[0][2], &input.graph[1][0],
			&input.graph[1][1], &input.graph[1][2], &input.graph[2][0], &input.graph[2][1], &input.graph[2][2]);
		input.code = encode(input);
		// process inputs
		if (visited[input.code]) {
			// 先印出步驟數
			printf("%d ", dis[input.code]);
			// backtrace
			nowCode = input.code;
			while (back[nowCode] != -1) {
				switch (op[nowCode]) {
					case 0:
						printf("H1");
						break;
					case 1:
						printf("H2");
						break;
					case 2:
						printf("H3");
						break;
					case 3:
						printf("V1");
						break;
					case 4:
						printf("V2");
						break;
					case 5:
						printf("V3");
						break;
				}
				nowCode = back[nowCode];
			}
			printf("\n");
		} else
			printf("Not solvable\n");
	}
	
	return 0;
}

void enqueue(Status num) {
	wait.push(num);
}

Status dequeue() {
	Status num = wait.front();
	wait.pop();
	return num;
}

bool empty() {
	return wait.empty();
}

int encode(Status input) {
	int code = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			code *= 10;
			code += input.graph[i][j];
		}
	return code;
}

// row, col: 代表第幾列第幾行要移動(0~2)
Status move(Status ori, int row, int col) {
	int temp;
	if (row != -1) {// 要移動 row 的話
		temp = ori.graph[row][0];
		ori.graph[row][0] = ori.graph[row][1];
		ori.graph[row][1] = ori.graph[row][2];
		ori.graph[row][2] = temp;
	}
	if (col != -1) {// 要移動 col 的話
		temp = ori.graph[2][col];
		ori.graph[2][col] = ori.graph[1][col];
		ori.graph[1][col] = ori.graph[0][col];
		ori.graph[0][col] = temp;
	}
	ori.code = encode(ori);
	return ori;
}