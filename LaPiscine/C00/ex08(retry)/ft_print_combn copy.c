#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}









void	ft_write(int n, int holders[])
{
	int		index;
    int     check;

	index = 0;
	while (index < n)
	{
		ft_putchar(48 + holders[index]);
		index++;
	}
	index = n - 1;
	last = 1;
	while (index >= 0)
	{
		if (holders[index] != 9 - (n - 1 - index))
		{
			last = 0; // 한 숫자 끝
            break ;
		}
		index--;
	}
	if (last == 0)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_recursive(int n, int curr, int holders[], int st_index)
{   //재귀 횟수=curr
	int index;
	int max;

	if (curr == n)
	{
		ft_write(n, holders);
	}
	else
	{
		max = 10 - (n - curr); // 6789 789
		index = st_index + 1;
		while (index <= max)
		{
			holders[curr] = index;
			ft_recursive(n, curr + 1, holders, index);
			index++;
		}
	}
}









void	ft_print_combn(int n)
{
	int holders[10];
	int index;

	index = 0;
	while (index < n)
	{
		holders[index] = 0;
		index++;
	}
	ft_recursive(n, 0, holders, -1);
}
