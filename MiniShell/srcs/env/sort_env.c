/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:28:47 by minslee           #+#    #+#             */
/*   Updated: 2022/08/24 10:12:58 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_env_len(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	sort_env(char **tab, int env_len)
{
	int		ordered;
	int		i;
	char	*tmp;

	ordered = 0;
	while (tab && ordered == 0)
	{
		ordered = 1;
		i = 0;
		while (i < env_len - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				ordered = 0;
			}
			i++;
		}
		env_len--;
	}
}

void	print_sorted_env_plus(char **tab, int *i)
{
	int	j;

	j = 0;
	ft_putstr("declare -x ");
	while (tab[*i][j] != '\0' && tab[*i][j] != '=')
		printf("%c", tab[*i][j++]);
	if (tab[*i][j] == '\0')
	{
		printf("\n");
		*i += 1;
		return ;
	}
	printf("=\"");
	j++;
	while (tab[*i][j] != '\0')
		printf("%c", tab[*i][j++]);
	printf("\"\n");
}

void	print_sorted_env(t_env *env)
{
	int		i;
	char	**tab;
	char	*str_env;

	str_env = env_to_str(env);
	tab = ft_split(str_env, '\n');
	ft_memdel(str_env);
	sort_env(tab, str_env_len(tab));
	i = 0;
	while (tab[i])
	{
		print_sorted_env_plus(tab, &i);
		i++;
	}
	free_tab(tab);
}
