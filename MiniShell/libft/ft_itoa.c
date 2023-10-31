/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:10:13 by minslee           #+#    #+#             */
/*   Updated: 2022/08/23 22:10:14 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	nbr;
	char	*s;
	int		div;
	int		i;

	i = 0;
	nbr = n;
	s = malloc(sizeof(char) * (ft_nbrlen(nbr) + 1));
	if (!s)
		return (NULL);
	if (nbr < 0)
	{
		s[i++] = '-';
		nbr = -nbr;
	}
	div = ft_power(10, ft_nbrlen(nbr) - 1);
	while (div > 0)
	{
		s[i++] = nbr / div + '0';
		nbr = nbr % div;
		div = div / 10;
	}
	s[i] = '\0';
	return (s);
}
