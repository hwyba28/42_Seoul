/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwsong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 07:30:50 by hwsong            #+#    #+#             */
/*   Updated: 2021/12/08 07:30:51 by hwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (dst[l] && l < size)
		l += 1;
	i = l;
	while (src[l - i] && l + 1 < size)
	{
		dst[l] = src[l - i];
		l++;
	}
	if (i < size)
		dst[l] = '\0';
	return (i + ft_strlen(src));
}
