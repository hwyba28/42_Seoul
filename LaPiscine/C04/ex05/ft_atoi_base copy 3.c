#include <unistd.h>
#include <stdio.h>

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

//int ft_atoi(char *str)
//{
//    int i;
//    int sign;
//    int result;
//
//    i = 0;
//    sign = 1;
//    result = 0;
//    while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
//        i++;
//    while (str[i] == '+' || str[i] == '-')
//    {
//        if (str[i] == '-')
//            sign *= -1;
//        i++;
//    }
//    while (str[i] >= '0' && str[i] <= '9')
//    {
//        result = str[i] - '0' + (result * 10);
//        i++;
//    }
//    return (result * sign);
//}


int ft_atoi_base(char *str, char *base) // "12" "012345678"
{
    int i;
    int j;
    int result;
    
    i = ft_strlen(str)-1;
    j = 0;
    result = 0;
    while ( i >= 0 )
    {
        while ( base[j] != '\n' )
        {
            j = 0;
            if ( str[i] == base[j] )
            {
                result = result * 10 + j;
                break;
            }
            j++;
        }
        i--;
    }
    
    return result;
}

int main (void)
{
    printf("%d",ft_atoi_base("bc","abc")); // 12
    ft_putchar('\n');
    return 0;
}
