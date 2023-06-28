/************************************
	Problem ID: UVa 112, TPC 7223 - Tree Summing 
	Programmer: SLMT
	Last Revised Date: 2013/4/18
************************************/
#include <cstdio>
#include <cstdlib>
#include <cctype>

using namespace std;

// ***** lexer variables and functinos ******
typedef enum ettype { TTYPE_NONE, TTYPE_CHAR, TTYPE_NUMBER, TTYPE_EOF } TType;
TType readType;
char readChar, nowCh;
int readNum;

void init(void);
void next(void);
bool isNumber(void);
bool isEOF(void);
int eatChar(void);
int eatNumber(void);

// ***** parser and checker
bool check;
int sum, n;
bool tree(void);

int main(void) {

	init();
	while (!isEOF()) {
		check = false;
		sum = 0;
		// read input
		n = eatNumber();
		if (tree())
			check = false;
		// output
		if (check)
			printf("yes\n");
		else
			printf("no\n");
	}
	
	return 0;
}

//***** lexer *****
void init(void) {
	nowCh = '\n';
	readType = TTYPE_NONE;
	next();
}

void next(void) {
	char num[10], numSize = 0;
	// 吃掉所有不需要的字元
	while (nowCh == '\n' || nowCh == ' ')
		nowCh = getc(stdin);

	if (nowCh == EOF)
		readType = TTYPE_EOF;
	else if (isdigit(nowCh) || nowCh == '-') { // 如果是數字(有可能為負)
		do {
			num[numSize++] = nowCh;
			nowCh = getc(stdin);
		} while (isdigit(nowCh));
		num[numSize] = '\0';
		readNum = atoi(num);
		readType = TTYPE_NUMBER;
	} else if (nowCh == '(' || nowCh == ')') {
		readChar = nowCh;
		readType = TTYPE_CHAR;
		nowCh = getc(stdin); // 抓下一次要用的字
	}

}

bool isNumber(void) {
	if (readType == TTYPE_NUMBER)
		return true;
	return false;
}

bool isEOF(void) {
	if (readType == TTYPE_EOF)
		return true;
	return false;
}

int eatChar(void) {
	next();
}

int eatNumber(void) {
	int num;
	num = readNum;
	next();
	return num;
}

//***** parser and checker *****
bool tree(void) { // return true if it's empty tree
	int num;
	bool leftEmpty, rightEmpty, empty = false;
	
	eatChar(); // eat '('
	if (isNumber()) { // 有數字，不是 empty tree
		num = eatNumber();
		
		sum += num;

		leftEmpty = tree();
		rightEmpty = tree();
		if (leftEmpty && rightEmpty && sum == n)
			check = true;

		sum -= num;
	} else // empty tree
		empty = true;
	eatChar(); // eat ')'
	
	return empty;
}
