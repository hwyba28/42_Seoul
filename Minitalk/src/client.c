#include "minitalk.h"

static void	ft_send_signal(int pid, char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(80);
	}
}

static char	*ft_str_to_bit(char *s, size_t i, size_t j)
{
	char	*res;
	int		c;
	int		bytes;

	i = ft_strlen(s);
	res = ft_calloc(i * 8 + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i + 1 != 0)
	{
		c = s[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				res[ft_strlen(s) * 8 - j - 1] = '1';
			else
				res[ft_strlen(s) * 8 - j - 1] = '0';
			c /= 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if (argc != 3)
	{
		ft_printf("Right Format: ./client PID ""\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	bits = ft_str_to_bit(argv[2], 0, 0);
	if (bits == NULL)
	{
		ft_printf("something went wrong\n");
		return (0);
	}
	ft_send_signal(pid, bits);
	free(bits);
}
