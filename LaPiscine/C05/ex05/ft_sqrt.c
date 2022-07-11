int		ft_sqrt(int nb)
{
	int	n;

	n = 1;
	if (nb > 0)
	{
		while (n * n <= nb)
		{
			if (n * n == nb)
				return (n);
			else if (n >= 46341) // 제곱근 최댓값 - int 오버플로우 안되게 (2147488281)
				return (0);
			n++;
		}
	}
	return (0); // 무리수
}
