#include <unistd.h>

#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
    int i;
    
    i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_put_itoa(int num)
{
	if (num > 9)
		ft_put_itoa(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_put_itoa(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		i++;
	}
}
