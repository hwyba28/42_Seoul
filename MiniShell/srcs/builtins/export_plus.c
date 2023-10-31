/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:21:16 by minslee           #+#    #+#             */
/*   Updated: 2022/08/24 08:47:14 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_new_env(t_env *env, char **args, int error_ret)
{
	if (error_ret == 2)
		return (2);
	else
		return (is_in_env(env, args[1]));
}
