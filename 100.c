#include <stdio.h>
#define MAX 100000

int main(void)
{
	int a[MAX],b[MAX],max[MAX]={0};
	int test,k,end;
	int n=0,i,times;
	
	while(scanf("%d %d",&a[n],&b[n]) == 2)
		n++;	

	for(i=0;i<n;i++) {
		
		if(a[i] <= b[i]) {
			test = a[i];
			end = b[i];
		} else {
			test = b[i];
			end = a[i];	
		}
		
		while( test <= end ) {
			times = 1;
			k = test;
			while( k != 1 ) {
				if( k%2 == 1 )
					k = k*3 + 1;
				else
					k /= 2;
				times++;
			}
			if(times > max[i])
				max[i] = times;
			test++;
		}
	}
	
	for(i=0;i<n;i++)
		printf("%d %d %d\n",a[i],b[i],max[i]);
	
	return 0;
}
