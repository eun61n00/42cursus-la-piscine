#ifndef GET_NEXT_LINE_LIST_H
# define GET_NEXT_LINE_LIST_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_list {
	int		fd;
	char	*backup;
	struct	s_node	*next;
} t_list;
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	split_nl(char **fd_list_fd, char **temp);
int		read_buff(int fd, char **fd_list, char **temp);
char	*read_line(int fd, char **fd_list);
char	*get_next_line(int fd);


#endif
