#include <stdio.h>

int abs(int num)
{
    if (num < 0)
        return (-1)*num;
    return num;
}

static int rx[10], ry[10];

int logic(int y, int x)
{
    int i;
    
    i = 0;
    while (i < y)
    {
        if (y == ry[i] || x == rx[i]) return 0;  //직선겹침
        if (abs(x - rx[i]) == abs(y - ry[i])) return 0; //대각겹침
        i++;
    }
 
    //마지막 체스판자리
    if (y == 9) return 1;
 
    //이전 퀸 위치들
    ry[y] = y, rx[y] = x;
 
    int rs = 0;
    int j = 0;
    while (j < 10)
    {
        rs += logic(y + 1, j);
        j++;
    }
 
    return rs;
}
int ft_ten_queens_puzzle(void){
    int i;
    int result;
    
    i = 0;
    result = 0;
    while (i < 10)
    {
        result += logic(0, i);
        i++;
    }
    return result;
}
//int main(void)
//{
//    printf("%d\n", ft_ten_queens_puzzle());
//    return 0;
//}

