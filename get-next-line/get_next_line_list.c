#include "get_next_line_list.h"

char	*read_line(int fd, t_list **cur_fd)
{

}

char	*get_next_line(int fd)
{
	char			*ret;
	static t_list	*fd_list;
	t_list			*cur_fd;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!fd_list)
	{
		fd_list->fd = fd;
		fd_list->backup = NULL;
		fd_list->next = NULL;
	}
	cur_fd = fd_list;
	while (cur_fd)
	{
		if (cur_fd->fd == fd)
			return (read_line(fd, &fd_list));
		cur_fd = cur_fd -> next;
	}
	ft_lstadd_back()

}