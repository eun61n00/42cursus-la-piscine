/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:26:30 by eukwon            #+#    #+#             */
/*   Updated: 2022/04/17 11:09:00 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# define BUFFER_SIZE 5

int	check_fd(int fd, t_list *fd_lst)
{
	t_list	*tmp;

	tmp = fd_lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_list	*check_init(int fd, t_list *fd_lst)
{
	t_list	*lst_ptr;

	lst_ptr = fd_lst;
	while (lst_ptr->fd != fd)
		lst_ptr = lst_ptr->next;
	if (!(lst_ptr->backup))
	{
		lst_ptr->backup = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!(lst_ptr->backup))
			return (NULL);
	}
	if (!(lst_ptr->buff))
	{
		lst_ptr->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!(lst_ptr->buff))
			return (NULL);
	}
	return (lst_ptr);
}

int	ft_read_buff(int fd, t_list *lst_ptr)
{
	int	ret;

	ret = read(fd, lst_ptr->buff, BUFFER_SIZE);
	lst_ptr->buff[ret] = '\0';
	if (ret <= 0)
	{
		free(lst_ptr->backup);
		free(lst_ptr->buff);
		return (0);
	}
	// else if (ret == 0)
	// 	return (0);
	return (1);
}

char	*ft_get_line(int fd, t_list *fd_lst)
{
	char	*newl;
	char	*temp;
	t_list	*lst_ptr;

	lst_ptr = check_init(fd, fd_lst);
	if (!lst_ptr)
		return (NULL);
	newl = ft_strchr(lst_ptr->backup, '\n');
	while (!newl)
	{
		if (!ft_read_buff(fd, lst_ptr))
			return (NULL);
		temp = ft_strjoin(lst_ptr->backup, lst_ptr->buff);
		if (lst_ptr->backup)
			free(lst_ptr->backup);
		if(lst_ptr->buff)
			free(lst_ptr->buff);
		lst_ptr->backup = temp;
		newl = ft_strchr(lst_ptr->backup, '\n');
	}
	temp = ft_substr(lst_ptr->backup, 0, (newl - (lst_ptr->backup)) + 1);
	// if (lst_ptr->backup)
	// 	free(lst_ptr->backup);
	// if(lst_ptr->buff)
	// 	free(lst_ptr->buff);
	lst_ptr->backup = ft_strchr(lst_ptr->backup, '\n') + 1;
	return (temp);
}

char	*get_next_line(int fd)
{
	static t_list	*fd_lst;
	t_list			*new_fd;

	if (!fd_lst)
	{
		fd_lst = (t_list *)malloc(sizeof(t_list));
		if (!fd_lst)
			return (NULL);
		fd_lst->fd = fd;
		fd_lst->backup = NULL;
		fd_lst->buff = NULL;
		fd_lst->next = NULL;
	}
	if (check_fd(fd, fd_lst))
		return (ft_get_line(fd, fd_lst));
	new_fd = (t_list *)malloc(sizeof(t_list));
	new_fd->fd = fd;
	new_fd->backup = NULL;
	new_fd->buff = NULL;
	new_fd->next = NULL;
	ft_lstlast(fd_lst)->next = new_fd;
	return (ft_get_line(fd, fd_lst));
}
