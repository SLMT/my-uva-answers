#include <stdio.h>

int Find_M(int n);

int main(void)
{
    int n[100],m[100];
    int i=0,j;

    scanf("%d",&n[i]);
    while(n[i] != 0) {
        i++;
        scanf("%d",&n[i]);
    }

    for(j=0;j<i;j++)
        printf("%d\n",Find_M(n[j]));
        
    return 0;
}

int Find_M(int n)
{
    int m,i,count,next,next_count;
    int area[100];
    
    for(m=1;m<n;m++) {
        count = 0;
        next = 0;
        for(i=0;i<n;i++)
            area[i] = 0;
        while(count < n) {
            /* �аO���w���q */
            area[next] = 1;
            count++;
            /* �Y�w����̫�@�ϨåB�O�� 13 ��(��12��)�h�^�� m */
            if(count == n && next == 12)
                return m;
            /* �M��U�@�� */
            next_count=0;
            while(next_count < m && count != n) {
                next++;
                next %= n;
                if(area[next] == 0)
                    next_count++;
            }
        }
    }
}
