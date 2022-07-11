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

int        ft_atoi(char *str)//atoi 원래는 문자열 -> 10 진수 정수 / 모양은 그대로
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
    int i;
    int nbr;
    int sign;
    int base_num;
    int result;
    char nbr_arr[32];
    
    if (ft_verify(base) == 0)
        return 0;
    nbr = ft_atoi(str);
    base_num = ft_strlen(base);
    sign = 1;
    if (nbr < 0)
    {
        nbr = -nbr;
        sign = -1;
    }
    else if (nbr == 0)
        return ft_atoi(base);
    i = 0;
    while (nbr > 0)
    {
        nbr_arr[i] = base[nbr % base_num];
        nbr /= base_num;
        i++;
    }
    while (--i >= 0)
        result = str[i] - '0' + (result * 10);
    return result*sign;//nbr_arr(i범위까지) -> 10진수로
    
}

//문자"123",문자"12" --> atoi-123 , "12" 진수 계산 --> 123의 이진법(12) -> 10진법으로 변환
int main (void)
{
    printf("%d",ft_atoi_base("123","12")); //"2222122" ->2222122
    ft_putchar('\n');
    return 0;
}
