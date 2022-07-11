#include <unistd.h>

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


//기수법으로 "123" "23" 첫번째 매개변수를
int ft_verify(char *base)
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

char *ft_putnbr_base(int nbr, char *base)
{
    int i;
    int base_num;
    char nbr_arr[32];
    char *arr_return;
    
    i = 0;
    base_num = ft_strlen(base);
    if (!ft_verify(base))
        return 0;
    
    if (nbr < 0)
    {
        nbr = -nbr;
        ft_putchar('-');
    }
    else if (nbr == 0)
    {
        ft_putchar(base[0]);
        return 0;
    }
    while (nbr > 0)
    {
        nbr_arr[i] = base[nbr % base_num];
        nbr /= base_num;
        i++;
    }
    while (--i >= 0)
        arr_return[i] = nbr_arr[i];
    return (arr_return);
}

int        ft_atoi(char *str)//atoi 원래는 문자열 -> 10 진수 정수
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;
    while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = str[i] - '0' + (result * 10);
        i++;
    }
    return (result * sign);
}


int ft_atoi_base(char *str, char *base)
{
    if (ft_verify(base) == 0)
        return 0;
    else
        return ft_atoi(ft_putnbr_base(ft_atoi(str),base));
}

int main (void)
{
    ft_atoi_base("20","pony_tale");
    ft_putchar('\n');
    return 0;
}
