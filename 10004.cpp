/************************************
	Problem ID: UVa 10004, TPC 7237 - Bicoloring
	Programmer: SLMT
	Last Revised Date: 2013/5/1
************************************/
#include <cstdio>
#include <vector>
#define NODE_MAX 200

using namespace std;

typedef enum e_status { UNDISCOVER, DISCOVER } Status;
typedef enum e_color { NO_COLOR, COLOR_1, COLOR_2 } Color;

vector<int> nodes[NODE_MAX];
Status status[NODE_MAX];
Color color[NODE_MAX];
int nodeNum;
bool isBicolor;

void DFSVisit(int now);

int main(void) {
	int m, u, v;
	
	while (scanf("%d", &nodeNum) == 1) {
		if (nodeNum == 0)
			break;
			
		// init
		for (int i = 0; i < nodeNum; i++) {
			nodes[i].clear();
			status[i] = UNDISCOVER;
			color[i] = NO_COLOR;
		}
		isBicolor = true;
		
		// read graph
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			nodes[u].push_back(v);
			nodes[v].push_back(u);
		}
		// DFS check
		color[0] = COLOR_1;
		status[0] = DISCOVER;
		DFSVisit(0);
		
		// output
		if (isBicolor)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}
	
	return 0;
}

void DFSVisit(int now) {
	status[now] = DISCOVER;
	for (unsigned i = 0; i < nodes[now].size(); i++) {
		if (status[nodes[now][i]] == UNDISCOVER) {
			color[nodes[now][i]] = (color[now] == COLOR_1)? COLOR_2 : COLOR_1;
			DFSVisit(nodes[now][i]);
		} else if (color[nodes[now][i]] == color[now])
			isBicolor = false;
	}
}