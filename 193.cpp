/************************************
	Problem ID: UVa 193, TPC 7238 - Graph Coloring 
	Programmer: SLMT
	Last Revised Date: 2013/5/
************************************/
#include <cstdio>
#include <vector>
#include <algorithm>
#define NODE_MAX 105

using namespace std;

typedef struct node {
	int index, degree;
} Node;
typedef enum e_status { UNDISCOVER, DISCOVER } Status;
typedef enum e_color { NO_COLOR, BLACK, WHITE } Color;

vector<int> nodes[NODE_MAX];
Status status[NODE_MAX];
Color color[NODE_MAX];
int nodeNum, colorCount;
Node degrees[NODE_MAX];

void DFSVisit(int now);
bool compare(Node a, Node b);

int main(void) {
	int caseCount, edgeNum, u, v;
	bool first;
	
	scanf("%d", &caseCount);
	for (unsigned i = 0; i < caseCount; i++) {
		scanf("%d %d", &nodeNum, &edgeNum);
		// init
		for (unsigned i = 1; i <= nodeNum; i++) {
			nodes[i].clear();
			status[i] = UNDISCOVER;
			color[i] = NO_COLOR;
			degrees[i].index = i;
			degrees[i].degree = 0;
		}
		colorCount = 0;
		first = true;
		
		// read graph
		for (unsigned i = 0; i < edgeNum; i++) {
			scanf("%d %d", &u, &v);
			nodes[u].push_back(v);
			degrees[u].degree++;
			nodes[v].push_back(u);
			degrees[v].degree++;
		}
		
		// Sort by degree
		sort(degrees + 1, degrees + nodeNum + 1, compare);
		
		// DFS
		for (unsigned i = 1; i <= nodeNum; i++) {
			int now = degrees[i].index;
			if (status[now] == UNDISCOVER) {
				color[now] = BLACK;
				colorCount++;
				DFSVisit(now);
			}
		}
		// output
		printf("%d\n", colorCount);
		for (unsigned i = 1; i <= nodeNum; i++)
			if (color[i] == BLACK) {
				if (first)
					first = false;
				else
					printf(" ");
				printf("%d", i);
			}
		printf("\n");
	}
	
	return 0;
}

void DFSVisit(int now) {
	status[now] = DISCOVER;
	for (unsigned i = 0; i < nodes[now].size(); i++) {
		int adj = nodes[now][i];
		if (status[adj] == UNDISCOVER) {
			bool noBlack = true;
			for (unsigned j = 0; j < nodes[adj].size(); j++)
				if (color[nodes[adj][j]] == BLACK)
					noBlack = false;
			if (noBlack) {
				color[adj] = BLACK;
				colorCount++;
			} else
				color[adj] = WHITE;
			DFSVisit(nodes[now][i]);
		}
	}
}

bool compare(Node a, Node b) {
	return a.degree < b.degree;
}