/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwsong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:14:08 by hwsong            #+#    #+#             */
/*   Updated: 2022/01/31 20:30:00 by hwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readstr(int fd, char *str)
{
	char	*buff;
	int		rbytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rbytes = 1;
	while (!ft_strchr(str, '\n') && rbytes != 0)
	{
		rbytes = read(fd, buff, BUFFER_SIZE);
		if (rbytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rbytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_readstr(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_oneline(str[fd]);
	str[fd] = ft_newstr(str[fd]);
	return (line);
}
