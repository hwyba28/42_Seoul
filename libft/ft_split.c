/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwsong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:38:52 by hwsong            #+#    #+#             */
/*   Updated: 2021/12/17 20:25:00 by hwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(char const *s, char c)
{
	int	ct;
	int	i;

	i = 0;
	ct = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			ct++;
		while (s[i] != c && s[i])
			i++;
	}
	return (ct);
}

char	*str(char const *s, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s, i + 1);
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**tmp;

	if (!s)
		return (NULL);
	len = count(s, c);
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		while (s[0] == c)
			s++;
		tmp[i] = str(s, c);
		if (!tmp[i])
			return (NULL);
		s = s + ft_strlen(tmp[i]);
	}
	tmp[i] = 0;
	return (tmp);
}
