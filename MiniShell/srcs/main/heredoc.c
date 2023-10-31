/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:13:09 by minslee           #+#    #+#             */
/*   Updated: 2022/08/24 11:13:12 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	is_heredoc_limiter(t_mini *mini, int fd)
{
	dup2(mini->fdin, fd);
	close(fd);
	exit(EXIT_SUCCESS);
}

void	heredoc_child(t_mini *mini)
{
	t_token	*tok;
	char	*line;
	int		fd;

	fd = open(".heredoc.tmp", (O_CREAT | O_TRUNC | O_RDWR), 0644);
	tok = mini->start;
	while (tok->next != NULL)
		tok = tok->next;
	ft_close(mini->fdout);
	while (1)
	{
		line = readline("\033[0;36m\033[1m> \033[0m");
		if (!line)
			continue ;
		if (!ft_strcmp(line, tok->str))
		{
			free(line);
			is_heredoc_limiter(mini, fd);
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line != NULL)
		free(line);
}

void	heredoc(t_mini *mini)
{
	pid_t	pid;
	int		status;

	pid = fork();
	signal(SIGQUIT, SIG_IGN);
	if (pid == 0)
		heredoc_child(mini);
	waitpid(pid, &status, 0);
	input(mini, ".heredoc.tmp");
}
