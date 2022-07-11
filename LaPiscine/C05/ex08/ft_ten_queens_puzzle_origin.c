#include <stdio.h>
#include <stdlib.h>
int N;
int vx[15+1], vy[15+1];

int go(int y, int x)
{
    //check valid (back tracking)
    for (int i = 0; i < y; i++) {
        if (y == vy[i] || x == vx[i]) return 0;  //직선겹침
        if (abs(x - vx[i]) == abs(y - vy[i])) return 0; //대각겹침
    }
 
    //terminal condition
    if (y == N - 1) return 1;
 
    //now record position
    vy[y] = y, vx[y] = x;
 
    //loop
    int r = 0;
    for (int i = 0; i < N; i++) {
        r += go(y + 1, i);
    }
 
    return r;
}
 
int main(void)
{
    scanf("%d", &N);
    int r = 0;
    for (int i = 0; i < N; i++) r += go(0, i);
    printf("%d\n", r);
    return 0;
}

