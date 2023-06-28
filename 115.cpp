/************************************
	Problem ID: UVa 115, TPC 7540 - Climbing Trees 
	Programmer: SLMT
	Last Revised Date: 2013/4/22
************************************/
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#define STR_MAX 35
#define NODE_MAX 300

using namespace std;

// Tree
map<string, int> indexTable;
map<int, string> inverseIndexTable;
vector<int> nodes[NODE_MAX], roots;

vector<char> findPath(int root, string target, vector<char> nowPath);

int main(void) {
	int nextIndex = 1;
	char str1[STR_MAX], str2[STR_MAX];
	
	// read tree data
	while (scanf("%s %s", str1, str2) == 2) {
		if (strcmp("no.child", str1) == 0)
			break;
		
		string child(str1), parent(str2);
		if (indexTable[child] == 0) {
			indexTable[child] = nextIndex;
			inverseIndexTable[nextIndex] = child;
			nextIndex++;
		}
		if (indexTable[parent] == 0) {
			indexTable[parent] = nextIndex;
			inverseIndexTable[nextIndex] = parent;
			nextIndex++;
		}
		
		// create relation
		nodes[indexTable[parent]].push_back(indexTable[child]);
	}
	
	// 尋找 root
	bool isRoot[NODE_MAX];
	for (int i = 0; i < NODE_MAX; i++)
		isRoot[i] = true;
	for (int i = 0; i < NODE_MAX; i++) {
		if (nodes[i].empty()) // 沒有 child 一定不會是 root
			isRoot[i] = false;
		else {
			// 這個 node 的 child 一定不是 root
			for (vector<int>::iterator it = nodes[i].begin(); it != nodes[i].end(); it++)
				isRoot[*it] = false;
		}
	}
	for (int i = 0; i < NODE_MAX; i++)
		if (isRoot[i])
			roots.push_back(i);
	
	// read query
	while (scanf("%s %s", str1, str2) == 2) {
		string p1(str1), p2(str2);
		bool noRelation = true;
		
		for (unsigned i = 0; i < roots.size(); i++) {
			vector<char> emptyPath;
			vector<char> p1Path = findPath(roots[i], p1, emptyPath);
			vector<char> p2Path = findPath(roots[i], p2, emptyPath);
			
			// 如果其中一個 path 是空的，兩者可能沒關係，或是在另一顆 tree 上
			if (p1Path.empty() || p2Path.empty())
				continue;
			
			// 接下來一定會有某種關係
			noRelation = false;
			// 先找相同的祖先
			int ancestor = 0;
			int ai, p1d, p2d, diff;
			for (ai = 0; ai < p1Path.size() && ai < p2Path.size(); ai++) {
				if (p1Path[ai] != p2Path[ai])
					break;
				ancestor = p1Path[ai];
			}
			p1d = p1Path.size() - ai;
			p2d = p2Path.size() - ai;
			diff = p1d - p2d;
			diff = (diff >= 0)? diff : -diff;
			if (p1d == 0) { // 代表 p1 是 p2 的直系祖先
				for (int t = 0; t < diff - 2; t++)
					printf("great ");
				if (diff > 1)
					printf("grand ");
				printf("parent\n");
				break;
			}
			if (p2d == 0) { // 代表 p1 是 p2 的直系孫子
				for (int t = 0; t < diff - 2; t++)
					printf("great ");
				if (diff > 1)
					printf("grand ");
				printf("child\n");
				break;
			}
			// 檢查是不是兄弟姊妹
			if (p1d == 1 && p2d == 1) {
				printf("sibling\n");
				break;
			}
			// 檢查其他親戚關係
			int con = (p1d < p2d)? p1d - 1 : p2d - 1;
			printf("%d cousin", con);
			if (diff > 0)
				printf(" removed %d", diff);
			printf("\n");
			break;
		}
		
		if (noRelation)
			printf("no relation\n");
	}
	
	return 0;
}

// 回傳從 root 到 target 經過的點(包含自己)
// 沒有結果回傳空的 path
vector<char> findPath(int parent, string target, vector<char> nowPath) {
	// 把這點進入進 path
	nowPath.push_back(parent);
	// 看看這點是不是目標
	if (inverseIndexTable[parent].compare(target) == 0)
		return nowPath;
	// 找找其他 subtree
	for (vector<int>::iterator it = nodes[parent].begin(); it != nodes[parent].end(); it++) {
		vector<char> path = findPath(*it, target, nowPath);
		if (!path.empty())
			return path;
	}
	// 都沒有的話傳空的 path 回去
	nowPath.clear();
	return nowPath;
}
