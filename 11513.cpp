/************************************
	Problem ID: UVa 11513, TPC 6007 - 9 Puzzle 
	Programmer: SLMT
	Last Revised Date: 2013/4/8
************************************/
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

// �O���ϧΪ��A����Ƶ��c
typedef struct status_t {
	int graph[3][3];
	int code; // �N�� graph ������
} Status;

queue<Status> wait;
void enqueue(Status num);
Status dequeue();
bool empty();

int encode(Status input);
Status move(Status ori, int row, int col);

int main(void) {
	map<int, bool> visited;
	map<int, int> dis, back, op; // dis: �Z��, back: �W�@�I, op: �q�W�@�I��o�I���ʪ���k
	Status start, now, adj[6], input;
	int nowCode;
	
	// BFS ��X�q��϶}�l���Ҧ��i��ʡA�íp��Z���P�����W�@�I
	// �_�I
	start.graph[0][0] = 1; start.graph[0][1] = 2; start.graph[0][2] = 3; 
	start.graph[1][0] = 4; start.graph[1][1] = 5; start.graph[1][2] = 6; 
	start.graph[2][0] = 7; start.graph[2][1] = 8; start.graph[2][2] = 9;
	start.code = encode(start); // ��ϧνs�X���@��Ʀr�A�@������
	// �����_�I��T
	visited[start.code] = true;
	dis[start.code] = 0;
	back[start.code] = -1; // �N����A���e trace
	op[start.code] = -1;
	enqueue(start);
	// ���� Graph
	while (!empty()) {
		now = dequeue();
		// ��X�o�ӹϧΥi�઺�ܤ�
		for (int i = 0; i < 3; i++) // �����Ҧ��C
			adj[i] = move(now, i, -1);
		for (int i = 0; i < 3; i++) // �U���Ҧ���
			adj[i + 3] = move(now, -1, i);
		// ���Ҧ����ʪ��i��
		for (int i = 0; i < 6; i++) {
			if (!visited[adj[i].code]) {
				visited[adj[i].code] = true; // �X�ݹL�o�ӹϧ�
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
			// ���L�X�B�J��
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

// row, col: �N��ĴX�C�ĴX��n����(0~2)
Status move(Status ori, int row, int col) {
	int temp;
	if (row != -1) {// �n���� row ����
		temp = ori.graph[row][0];
		ori.graph[row][0] = ori.graph[row][1];
		ori.graph[row][1] = ori.graph[row][2];
		ori.graph[row][2] = temp;
	}
	if (col != -1) {// �n���� col ����
		temp = ori.graph[2][col];
		ori.graph[2][col] = ori.graph[1][col];
		ori.graph[1][col] = ori.graph[0][col];
		ori.graph[0][col] = temp;
	}
	ori.code = encode(ori);
	return ori;
}