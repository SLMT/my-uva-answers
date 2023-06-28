/************************************
	Problem ID: UVa 10281
	Programmer: SLMT
	Last Revised Date: 2012/12/11
************************************/
#include <stdio.h>

typedef struct {
	int hr, min, sec;
} Time;

Time getTime(int hr, int min, int sec);
void printTime(Time t);
double disInHour(Time a, Time b);

int main(void) {
	Time lastTime, time;
	int hr, min, sec, speed;
	double hr_dis, distance;
	char ch;
	
	lastTime = getTime(0, 0, 0);
	speed = 0;
	distance = 0.0;
	while (scanf("%d:%d:%d", &hr, &min, &sec) == 3) {
		/* 紀錄時間 */
		time = getTime(hr, min, sec);
		/* 計算距離 */
		hr_dis = disInHour(lastTime, time);
		distance += hr_dis * speed;
		lastTime = time;
		
		ch = fgetc(stdin);
		if (ch == ' ') { /* 代表後面還有速度 */
			scanf("%d", &speed);
		} else {
			printTime(time);
			printf(" %.2lf km\n", distance);
		}
	}
	
	return 0;
}

Time getTime(int hr, int min, int sec) {
	Time time;
	time.hr = hr;
	time.min = min;
	time.sec = sec;
	return time;
}

void printTime(Time t) {
	printf("%02d:%02d:%02d", t.hr, t.min, t.sec);
}

double disInHour(Time a, Time b) {
	double hr1, hr2;
	
	hr1 = a.hr + (double)(a.min) / 60 + (double)(a.sec) / 3600;
	hr2 = b.hr + (double)(b.min) / 60 + (double)(b.sec) / 3600;
	
	return hr2 - hr1;
}