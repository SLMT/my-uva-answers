/************************************
	Problem ID: UVa 417, TPC 7204 - Word Index 
	Programmer: SLMT
	Last Revised Date: 2013/4/1
************************************/
#include <cstdio>
#include <map>
#include <string>
#include <ctime>
#define MAX 6

using namespace std;

int main(void) {
	map<string, int> table;
	int i, j, k, l, m, code = 1;
	string temp, alphas[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	char buffer[MAX];
	
	// 建表，暴力法
	for (i = 0; i < 26; i++) {
		temp = alphas[i];
		table[temp] = code++;
	}
	for (i = 0; i < 26; i++)
		for (j = i + 1; j < 26; j++) {
			temp = alphas[i] + alphas[j];
			table[temp] = code++;
		}
	for (i = 0; i < 26; i++)
		for (j = i + 1; j < 26; j++)
			for (k = j + 1; k < 26; k++) {
				temp = alphas[i] + alphas[j] + alphas[k];
				table[temp] = code++;
			}
	for (i = 0; i < 26; i++)
		for (j = i + 1; j < 26; j++)
			for (k = j + 1; k < 26; k++) 
				for (l = k + 1; l < 26; l++) {
					temp = alphas[i] + alphas[j] + alphas[k] + alphas[l];
					table[temp] = code++;
				}
	for (i = 0; i < 26; i++)
		for (j = i + 1; j < 26; j++)
			for (k = j + 1; k < 26; k++) 
				for (l = k + 1; l < 26; l++) 
					for (m = l + 1; m < 26; m++) {
						temp = alphas[i] + alphas[j] + alphas[k] + alphas[l] + alphas[m];
						table[temp] = code++;
					}
					
	// read input
	while (scanf("%s", buffer) == 1) {
		temp = buffer;
		printf("%d\n", table[temp]);
	}
	
	return 0;
}