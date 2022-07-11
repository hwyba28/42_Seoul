#include <unistd.h>

void    ft_putstr(char *str)
{
    int c;

    c = 0;
    while (str[c] != '\0')
    {
        write(1, &str[c], 1);
        c++;
    }
    write(1, "\n", 1);
}


//void    ft_swap(int *a, int *b)
//{
//    int tmp;
//
//    tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//


int ft_strcmp(char *s1, char *s2)
{
    int c;

    c = 0;
    while ((s1[c] == s2[c]) && (s1[c] != '\0') && (s2[c] != '\0'))
        c++;
    return (s1[c] - s2[c]);
}

int        main(int argc, char **argv)
{
    char    *tmp;
    int s;
    int i;

    s = 1;
    while (s)
    {
        s = 0;
        i = 0;
        while (++i < argc - 1)
        {
            if (ft_strcmp(argv[i], argv[i + 1]) > 0)
            {
                tmp = argv[i];
                argv[i] = argv[i + 1];
                argv[i + 1] = tmp;
                s = 1;
            }
        }
    }
    i = 0;
    while (++i < argc){
        ft_putstr(argv[i]);
    }
    return (0);
}
