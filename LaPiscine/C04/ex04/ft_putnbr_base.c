/*ptest 모든 테스트 케이스
 int 형 범위 다 넣어주기*/



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

int ft_verify(char *base)
{
    int i;
    int j;
    //조건1) 기수가 비어있거나 크기가 1인 경우
    if (ft_strlen(base) < 2)
        return (0);
    i = 0;
    while (base[i])
    {//조건2) (유효하지 않은 말고) 공백 인자 또는 +-가 들어있을 때,
        if (base[i] == '-' || base[i] == '+' || base[i] == '\t' || base[i] == '\n'
            || base[i] == '\v' || base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
            return (0);
        j = i + 1;
        while (base[j])
        {//조건3) 동일한 문자가 2번 들어있을 때,
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void ft_putnbr_base(int nbr, char *base)
{
    int i;
    int base_num;
    char nbr_arr[32];
    
    i = 0;
    base_num = ft_strlen(base);
    if (!ft_verify(base))
        return ;
    
    if (nbr < 0)
    {
        nbr *= (-1); // 부호 방식 주의!
        ft_putchar('-');
    }
    else if (nbr == 0)
    {
        ft_putchar(base[0]);
        return ;
    }
    while (nbr > 0)
    {
        nbr_arr[i] = base[nbr % base_num];
        nbr /= base_num;
        i++;
    }
    while (--i >= 0)
        ft_putchar(nbr_arr[i]);
}

int main (void)
{
//    ft_putnbr_base(20,"po");
    ft_putnbr_base(20,"pony_tale");//20을 9진수로 22이므로 nn
//    ft_putnbr_base(32,"0123456789ABCDEF");
    ft_putchar('\n');
    return 0;
}
