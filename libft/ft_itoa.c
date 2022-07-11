/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwsong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:25:35 by hwsong            #+#    #+#             */
/*   Updated: 2021/12/18 04:07:31 by hwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(long n)
{
	int	l;

	l = 0;
	if (n < 0)
	{
		n = n * (-1);
		l++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	int		l;

	num = (long) n;
	l = len(n);
	result = (char *)malloc(sizeof(char) * (l + 1));
	if (!result)
		return (NULL);
	result[l] = '\0';
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		result[0] = '-';
		num = num * (-1);
	}
	while (num > 0)
	{
		result[--l] = 48 + (num % 10);
		num = num / 10;
	}
	return (result);
}
