/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:11:35 by minslee           #+#    #+#             */
/*   Updated: 2022/08/23 22:33:41 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_first(const char *str, char c)
{
	int	k;

	k = 0;
	while (str[k] == c)
		k++;
	return (k);
}

static int	word_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		count++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c)
			i++;
	}
	return (count);
}

static int	letter_count(char const *s, char c, int index)
{
	int		count;

	count = 0;
	while (s[index] != c && s[index] != '\0')
	{
		count++;
		index++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	tab = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !c || !tab)
		return (NULL);
	k = get_first(s, c);
	while (s[k] != '\0')
	{
		j = 0;
		tab[i] = malloc(sizeof(char) * letter_count(s, c, k) + 1);
		if (!tab[i])
			return (NULL);
		while (s[k] != c && s[k] != '\0')
			tab[i][j++] = s[k++];
		tab[i++][j] = '\0';
		while (s[k] == c)
			k++;
	}
	tab[i] = NULL;
	return (tab);
}
