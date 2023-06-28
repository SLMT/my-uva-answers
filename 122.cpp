/************************************
	Problem ID: UVa 122, TPC 7542 - Trees on the level 
	Programmer: SLMT
	Last Revised Date: 2013/4/22
************************************/
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

typedef struct node_t {
	int num;
	struct node_t *left, *right;
} Node;

typedef enum readMode { READ_LEFT, READ_NUM, READ_PATH} ReadMode;

Node *root;

bool insert(int num, char *pathStr, int pathSize);
Node *createNode(void);
vector<int> browseTree(void);
void deleteTree(Node *parent);

int main(void) {
	char ch, numStr[15], path[300];
	bool falseTree, readDone, allDone = false;
	int numStrSize, pathSize, num;
	ReadMode rm;
	
	while (!allDone) {
		// 試著讀取第一個 '('
		while ((ch = getc(stdin)) != '(')
			if (ch == EOF) {
				allDone = true;
				break;
			}
		
		// 讀取節點
		rm = READ_NUM;
		numStrSize = 0;
		pathSize = 0;
		readDone = false;
		falseTree = false;
		root = NULL;
		while (!allDone && !readDone) {
			ch = getc(stdin);
			switch (rm) {
				case READ_LEFT:
					if (ch == '(')
						rm = READ_NUM;
					break;
				case READ_NUM:
					if (ch == ')')
						readDone = true;
					else if (ch >= '0' && ch <= '9')
						numStr[numStrSize++] = ch;
					else if (ch == ',') {
						numStr[numStrSize] = '\0';
						num = atoi(numStr);
						numStrSize = 0;
						rm = READ_PATH;
					}
					break;
				case READ_PATH:
					if (ch != ')')
						path[pathSize++] = ch;
					else {
						// 將點放入 tree
						if (!falseTree)
							if (!insert(num, path, pathSize))
								falseTree = true;
						pathSize = 0;
						rm = READ_LEFT;
					}
					break;
			}
		}
		
		// 輸出 tree
		if (root != NULL) {
			if (falseTree)
				printf("not complete");
			else {
				vector<int> out = browseTree();
				bool first;
				if (out.empty())
					printf("not complete");
				else {
					printf("%d", out[0]);
					for (vector<int>::size_type i = 1; i < out.size(); i++)
						printf(" %d", out[i]);
				}
			}
			printf("\n");
			deleteTree(root);
		}
	}
	
	return 0;
}

// 回傳 false 代表插入失敗
bool insert(int num, char *pathStr, int pathSize) {
	Node *now, *last;
	
	// 先看看有沒有 root
	if (root == NULL) {
		root = createNode();
		root->num = -1;
	}
	
	// 從 root 開始尋找正確的位置
	now = root;
	for (int i = 0; i < pathSize; i++) {
		last = now;
		if (pathStr[i] == 'L')
			now = now->left;
		else
			now = now->right;
		// 如果這個位置沒有點的話，就先放個假的點進去
		if (now == NULL) {
			now = createNode();
			now->num = -1;
			if (pathStr[i] == 'L')
				last->left = now;
			else
				last->right = now;
		}
	}
	// 看看這個點是否已經有資料
	if (now->num == -1)
		now->num = num;
	else
		return false;
	return true;
}

Node *createNode(void) {
	Node *newNode;
	
	newNode = (Node *)malloc(sizeof(Node));
	newNode->num = -1;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

// 用 BFS 來顯示 tree 的內容
vector<int> browseTree(void) {
	queue<Node*> q;
	Node *now;
	vector<int> output;
	// 起點為 root
	q.push(root);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		// 看看是否有 child
		if (now->left != NULL)
			q.push(now->left);
		if (now->right != NULL)
			q.push(now->right);
		// output
		if (now->num != -1)
			output.push_back(now->num);
		else {
			// 有節點沒有資料，錯誤的 tree
			output.clear();
			return output;
		}
	}
}

// DFS 刪除 tree
void deleteTree(Node *parent) {
	if (parent != NULL) {
		deleteTree(parent->left);
		deleteTree(parent->right);
		free(parent);
	}
}








