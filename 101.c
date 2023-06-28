/**************************/
/*  Problem¡G UVa 101     */
/*  Writer¡GSLMT          */
/**************************/

#include <stdio.h>

void clear_up(int *up,int *po,int now);
void move(int *up,int *po,int target,int place);
int check(int *up,int a,int b);

int main(void)
{
    int up[25],po[25],n,a,b;
    int i,now;
    char ch,act1[10],act2[10];
    
    while(scanf("%d",&n) == 1) {
        for(i=0;i<n;i++)
            po[i] = 1;
        for(i=0;i<25;i++)
            up[i] = -1;
        
        ch = 0;
        while(ch != 'q') {
            ch = getchar();
            ungetc(ch,stdin);
            if(ch == 'm' || ch == 'p') {
                scanf("%s %d %s %d",act1,&a,act2,&b);
                if(check(up,a,b)) {
                    if(act1[0] == 'm' && act2[1] == 'n') {
                        clear_up(up,po,a);
                        clear_up(up,po,b);
                        move(up,po,a,b);
                    } else if(act1[0] == 'm' && act2[1] == 'v') {
                        clear_up(up,po,a);
                        now = b;
                        while(up[now] != -1)
                            now = up[now];
                        move(up,po,a,now);
                    } else if(act1[0] == 'p' && act2[1] == 'n') {
                        clear_up(up,po,b);
                        move(up,po,a,b);
                    } else if(act1[0] == 'p' && act2[1] == 'v') {
                        now = b;
                        while(up[now] != -1)
                            now = up[now];
                        move(up,po,a,now);
                    }
                }
            } else
                while(getchar() != '\n'); /* eat remaining line */
        }
        /* output */
        for(i=0;i<n;i++) {
            printf("%d:",i);
            if(po[i] == 1) {
                printf(" %d",i);
                now = i;
                while(up[now] != -1) {
                    printf(" %d",up[now]);
                    now = up[now];
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}

void clear_up(int *up,int *po,int now)
{
    int temp;
    
    while(up[now] != -1) {
        temp = now;
        now = up[now];
        up[temp] = -1;
        po[now] = 1;
    }
}

void move(int *up,int *po,int target,int place)
{
    int i;
    
    po[target] = 0;
    up[place] = target;
    for(i=0;i<25;i++)
        if(up[i] == target && i != place)
            up[i] = -1;
}

int check(int *up,int a,int b)
{
    int now;
    
    if(a == b)
        return 0;
    else {
        now = a;
        while(up[now] != -1) {
            if(up[now] == b)
                return 0;
            now = up[now];
        }
        now = b;
        while(up[now] != -1) {
            if(up[now] == a)
                return 0;
            now = up[now];
        }
    }
    return 1;
}
