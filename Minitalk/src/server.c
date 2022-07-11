#include "minitalk.h"

static void	ft_print_binary(char *s)
{
	int				b;
	unsigned char	c;
	size_t			i;

	b = 1;
	c = 0;
	i = ft_strlen(s) - 1;
	while (i + 1 != 0)
	{
		c += b * (s[i] - '0');
		b *= 2;
		i--;
	}
	write(1, &c, 1);
}

static void	ft_read_bit(int sig)
{
	static char	*bits;
	static int	bitcount;

	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_appendc(bits, '0');
	else
		bits = ft_appendc(bits, '1');
	if (bitcount == 8)
	{
		ft_print_binary(bits);
		free(bits);
		bits = NULL;
	}
}

int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_read_bit);
		signal(SIGUSR2, ft_read_bit);
		pause();
	}
	return (0);
}
