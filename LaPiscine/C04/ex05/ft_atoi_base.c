#include <unistd.h>
//#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}


int ft_verify_base(char *base)
{
    int i;
    int j;
    
    if (ft_strlen(base) < 2)
        return (0);
    i = 0;
    while (base[i])
    {
        if (base[i] == '-' || base[i] == '+' || base[i] == '\t' || base[i] == '\n'
            || base[i] == '\v' || base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
            return (0);
        j = i + 1;
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

int ft_atoi_base(char *str, char *base) // "ab" "abcdefg"
{
    int i;
    int j;
    int radix;
    int result;
    
    if(!(ft_verify_base(base)))
        return 0;
    i = 0;
    radix = ft_strlen(base);
    result = 0;
    while ( str[i] != '\0')
    {
        j = 0;
        while (base[j] != '\0')
        {
            if (str[i] == base[j])
                result = (result * 10) + j;
                j++;
        }
        i++;
    }
    return result;
}

//int main (void)
//{   ft_verify_base(
//    printf("%d",ft_atoi_base("bc","abc")); // 12
//    return 0;
//}
