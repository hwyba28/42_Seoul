#include <unistd.h>

void    ft_putchar(char c)
{
    write(1,&c,1);
}
int        verify(char *base)
{
    int    i;
    int    j;

    i = 0;
    j = 0;
    if (base[0] == '\0' || base[1] == '\0')
        return (0);
    while (base[i])
    {
        j = i + 1;
        if (base[i] == '+' || base[i] == '-')
            return (0);
        if (base[i] < 32 || base[i] > 126)
            return (0);
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void    ft_putnbr_base(int nbr, char *base)
{
    int    size;
    int    nbr_arr[100];
    int    i;

    i = 0;
    size = 0;
    if (verify(base))
    {
        if (nbr < 0)
        {
            nbr = -nbr;
            ft_putchar('-');
        }
        while (base[size])
            size++;
        while (nbr)
        {
            nbr_arr[i] = nbr % size; //몇 진수라는 것은 그 수 단위로 나눠서 출력하겠다는 의미
            nbr = nbr / size;
            i++;
        }
        while (--i >= 0)
            ft_putchar(base[nbr_arr[i]]);
    }
}

//int     main(void)
//{
//    char base[]="136fgwshj";
//    ft_putnbr_base(8,base);
//    return (0);
//}
