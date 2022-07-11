#include <stdlib.h>

int        *ft_range(int min, int max)
{
    int *range;
    int i;

    if (min >= max)
        return (0);
    range = (int *)malloc(sizeof(int)*(max - min));
    if (range == NULL)
        return (0);
    i = 0;
    while (min < max)
    {
        range[i] = min;
        i++;
        min++;
    }
    return (range);
}


//#include <stdio.h>
//int main (void)
//{
//    int i = 0;
//    int *sample = ft_range(4,6);
//    while(sample[i] != '\0'){
//    printf("%d",sample[i]);
//        i++;
//    }
//}
