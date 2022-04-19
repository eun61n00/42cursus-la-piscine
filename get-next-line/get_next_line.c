/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:24:49 by eukwon            #+#    #+#             */
/*   Updated: 2022/04/19 12:20:30 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "limits.h"
#define BUFFER_SIZE 5

int	read_buff(int fd, char **fd_list, char *temp)
{
	int		ret;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret <= 0)
	{
		free(buff);
		if (fd_list[fd])
		{
			temp = ft_strdup(fd_list[fd]);
			fd_list[fd] = NULL;
			free(fd_list[fd]);
			return (0);
		}
		else
			return (-1);
	}
	buff[ret] = '\0';
	temp = ft_strjoin(fd_list[fd], buff);
	free(fd_list[fd]);
	fd_list[fd] = temp;
	return (1);
}

char	*read_line(int fd, char **fd_list)
{
	int		ret;
	char	*buff;
	char	*newl;
	char	*temp;
	char	*temp2;

	newl = NULL;
	while (!newl)
	{
		ret = read_buff(fd, fd_list, temp);
		if (ret == -1)
			return (NULL);
		else if (ret == 0)
			return (temp);
		else
			newl = ft_strchr(fd_list[fd], '\n');
	}
	temp = ft_substr(fd_list[fd], 0, (newl - (fd_list[fd])) + 1);
	temp2 = ft_strdup(ft_strchr(fd_list[fd], '\n') + 1);
	free(fd_list[fd]);
	fd_list[fd] = temp2;
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*fd_list[OPEN_MAX + 1];

	if (fd > OPEN_MAX)
		return (NULL);
	ret = read_line(fd, fd_list);
	if (!ret)
		return (NULL);
	return (ret);
}
