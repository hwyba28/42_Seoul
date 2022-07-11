/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwsong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:52:57 by hwsong            #+#    #+#             */
/*   Updated: 2021/12/17 20:57:03 by hwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	if (n == 0)
		return (0);
	c = 0;
	while (s1[c] != '\0' && s2[c] != '\0' && s1[c] == s2[c] && n > c + 1)
		++c;
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
