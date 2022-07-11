#include <stdlib.h>

char    *ft_strjoin(int size, char **strs, char *sep)
{
    char    *str;
    int        i;
    int        j;
    int        c;

    str = malloc(sizeof(strs));
    i = 0;
    c = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j] != '\0')
        {
            str[c++] = strs[i][j++];
        }
        j = 0;
        while (sep[j] != '\0' && i != size - 1)
        {
            str[c++] = sep[j++];
        }
        i++;
    }
    str[c] = '\0';
    return (str);
}
