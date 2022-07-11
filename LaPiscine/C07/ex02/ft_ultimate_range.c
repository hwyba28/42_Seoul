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

int        ft_ultimate_range(int **range, int min, int max)
{
    *range = ft_range(min, max);
    if (*range == NULL)
        return (0);
    return (max - min);
}
