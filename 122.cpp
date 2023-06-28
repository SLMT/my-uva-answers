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
		// �յ�Ū���Ĥ@�� '('
		while ((ch = getc(stdin)) != '(')
			if (ch == EOF) {
				allDone = true;
				break;
			}
		
		// Ū���`�I
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
						// �N�I��J tree
						if (!falseTree)
							if (!insert(num, path, pathSize))
								falseTree = true;
						pathSize = 0;
						rm = READ_LEFT;
					}
					break;
			}
		}
		
		// ��X tree
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

// �^�� false �N���J����
bool insert(int num, char *pathStr, int pathSize) {
	Node *now, *last;
	
	// ���ݬݦ��S�� root
	if (root == NULL) {
		root = createNode();
		root->num = -1;
	}
	
	// �q root �}�l�M�䥿�T����m
	now = root;
	for (int i = 0; i < pathSize; i++) {
		last = now;
		if (pathStr[i] == 'L')
			now = now->left;
		else
			now = now->right;
		// �p�G�o�Ӧ�m�S���I���ܡA�N����Ӱ����I�i�h
		if (now == NULL) {
			now = createNode();
			now->num = -1;
			if (pathStr[i] == 'L')
				last->left = now;
			else
				last->right = now;
		}
	}
	// �ݬݳo���I�O�_�w�g�����
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

// �� BFS ����� tree �����e
vector<int> browseTree(void) {
	queue<Node*> q;
	Node *now;
	vector<int> output;
	// �_�I�� root
	q.push(root);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		// �ݬݬO�_�� child
		if (now->left != NULL)
			q.push(now->left);
		if (now->right != NULL)
			q.push(now->right);
		// output
		if (now->num != -1)
			output.push_back(now->num);
		else {
			// ���`�I�S����ơA���~�� tree
			output.clear();
			return output;
		}
	}
}

// DFS �R�� tree
void deleteTree(Node *parent) {
	if (parent != NULL) {
		deleteTree(parent->left);
		deleteTree(parent->right);
		free(parent);
	}
}








