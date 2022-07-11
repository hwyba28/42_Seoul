//#include <stdio.h>

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	while (nb > i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}


//int main(void)
//{
//    printf("%d",ft_is_prime(38));
//    printf("\n");
//    printf("%d",ft_is_prime(37));
//    printf("\n");
//}
