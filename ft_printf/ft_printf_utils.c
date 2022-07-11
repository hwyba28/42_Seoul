#include "ft_printf.h"

int    ft_printchar(int c)
{
    write(1, &c, 1);
    return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
//printf("%s",NULL)
int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int    ft_printpercent(void)
{
    write(1, "%", 1);
    return (1);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*numstr;

	len = 0;
	numstr = ft_itoa(n);
	len = ft_printstr(numstr);
	free(numstr);
	return (len);
}
//포인터 동적 메모리 해제
