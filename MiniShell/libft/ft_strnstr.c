/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:23:05 by minslee           #+#    #+#             */
/*   Updated: 2022/08/24 08:03:37 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_str(char *s_tmp, char *f_tmp, size_t len, size_t index)
{
	size_t	f_index;
	size_t	s_index;

	s_index = 0;
	f_index = 0;
	while (f_tmp[f_index])
	{
		if (index == len)
			return (0);
		if (s_tmp[s_index] != f_tmp[f_index] || index == len)
			return (0);
		s_index++;
		f_index++;
		index++;
	}
	return (1);
}

static int	is_equal(const char *src, const char *find, size_t len)
{
	size_t	index;

	index = 0;
	if (ft_strlen(src) == ft_strlen(find) && ft_strlen(src) == len)
	{
		while (index < len)
		{
			if (src[index] != find[index])
				return (0);
			index++;
		}
		return (1);
	}
	else
		return (0);
}

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	char	*s_tmp;
	char	*f_tmp;
	size_t	index;

	index = 0;
	s_tmp = (char *)src;
	if (is_equal(src, find, len) || *find == 0)
		return (s_tmp);
	if (len == 0)
		return (0);
	while (*s_tmp && index < len)
	{
		f_tmp = (char *)find;
		if (*s_tmp == *f_tmp)
		{
			if (find_str(s_tmp, f_tmp, len, index))
				return (s_tmp);
		}
		s_tmp++;
		index++;
	}
	return (0);
}
