/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 09:36:06 by eukwon            #+#    #+#             */
/*   Updated: 2022/04/17 17:20:05 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# define BUFFER_SIZE 5

t_list	*find_fd(int fd, t_list *fd_list)
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

static void	delete_fd(int fd, t_list **fd_list)
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
	}
	else
	{
		while(temp->next)
		{
			if (temp->next->fd == fd)
			{
				temp2 = temp->next->next;
				free(temp->next);
				temp->next = temp2;
				return ;
			}
			temp = temp->next;
		}
	}
}

static char	*ft_read(int fd, t_list **fd_list, char *temp, t_list **cur_fd)
{
	int		ret;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == 0)
	{
		free(buff);
		delete_fd(fd, fd_list);
		if (temp)
			return (temp);
		else
			return (NULL);
	}
	else if (ret < 0)
	{
		free(buff);
		return (NULL);
	}
	buff[ret] = '\0';
	temp = ft_strjoin((*cur_fd)->backup, buff);
	return (temp);
}

char	*read_line(int fd, t_list **cur_fd, t_list **fd_list)
{
	char	*newl;
	char	*temp;
	char	*temp2;

	newl = NULL;
	temp = NULL;
	while (!newl)
	{
		temp = ft_read(fd, fd_list, temp, cur_fd);
		if (!temp)
			return (NULL);
		if (!(*cur_fd))
			return (temp);
		free((*cur_fd)->backup);
		(*cur_fd)->backup = temp;
		newl = ft_strchr((*cur_fd)->backup, '\n');
	}
	temp = ft_substr((*cur_fd)->backup, 0, (newl - ((*cur_fd)->backup)) + 1);
	temp2 = ft_strdup(ft_strchr((*cur_fd)->backup, '\n') + 1);
	free((*cur_fd)->backup);
	(*cur_fd)->backup = temp2;
	return (temp);
}

char	*get_next_line(fd)
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
		new_fd->backup = ft_strdup("");
		new_fd->next = NULL;
		ft_lstadd_back(&fd_list, new_fd);
		cur_fd = new_fd;
	}
	ret = read_line(fd, &cur_fd, &fd_list);
	if (!ret)
		return (NULL);
	return (ret);

}
