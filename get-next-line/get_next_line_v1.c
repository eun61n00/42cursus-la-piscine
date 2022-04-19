/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 09:36:06 by eukwon            #+#    #+#             */
/*   Updated: 2022/04/19 12:20:47 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# define BUFFER_SIZE 5

static t_list	*find_fd(int fd, t_list *fd_list)
{
	t_list	*tmp;

	tmp = fd_list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	del_fd(int fd, t_list **fd_list)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *fd_list;
	if (temp->fd == fd)
	{
		temp = (*fd_list)->next;
		free((*fd_list)->backup);
		free(*fd_list);
		*fd_list = temp;
		return ;
	}
	while (temp->next)
	{
		if (temp->next->fd == fd)
		{
			temp2 = temp->next->next;
			free(temp->next->backup);
			free(temp->next);
			temp->next = temp2;
			return ;
		}
		temp = temp->next;
	}
}

static int	read_buff(int fd, t_list *cur_fd, t_list **fd_list, \
char **temp, char *buff)
{
	int	ret;

	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == 0)
	{
		free(buff);
		if (cur_fd->backup)
		{
			*temp = cur_fd->backup;
			cur_fd->backup = NULL;
			return (-1);
		}
		del_fd(fd, fd_list);
		if (temp)
			return (-1);
		else
			return (0);
	}
	else if (ret < 0)
	{
		free(buff);
		return (0);
	}
	buff[ret] = '\0';
	return (1);
}

static char	*read_line(int fd, t_list *cur_fd, t_list **fd_list)
{
	int		ret;
	char	*buff;
	char	*newl;
	char	*temp;
	char	*temp2;

	newl = NULL;
	temp = NULL;
	while (!newl)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		ret = read_buff(fd, cur_fd, fd_list, &temp, buff);
		if (ret == 0)
			return (NULL);
		else if (ret == -1)
			return (temp);
		temp = ft_strjoin(cur_fd->backup, buff);
		free(cur_fd->backup);
		cur_fd->backup = temp;
		newl = ft_strchr(cur_fd->backup, '\n');
	}
	temp = ft_substr(cur_fd->backup, 0, (newl - (cur_fd->backup)) + 1);
	temp2 = ft_strdup(ft_strchr(cur_fd->backup, '\n') + 1);
	free(cur_fd->backup);
	cur_fd->backup = temp2;
	return (temp);
}

char	*get_next_line(int fd)
{
	static t_list	*fd_list;
	t_list			*new_fd;
	t_list			*cur_fd;
	char			*ret;

	cur_fd = find_fd(fd, fd_list);
	if (!cur_fd)
	{
		new_fd = (t_list *)malloc(sizeof(t_list));
		if (!new_fd)
			return (NULL);
		new_fd->fd = fd;
		new_fd->backup = NULL;
		new_fd->next = NULL;
		ft_lstadd_back(&fd_list, new_fd);
		cur_fd = new_fd;
	}
	ret = read_line(fd, cur_fd, &fd_list);
	if (!ret)
		return (NULL);
	return (ret);
}
