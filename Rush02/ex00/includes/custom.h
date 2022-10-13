#ifndef CUSTOM_H
# define CUSTOM_H
# define MAX_BUF 1000
# define BUCKET_SIZE 16
# define INIT_DICT "./numbers.dict"
# define COM_ERR "Error\n"
# define DICT_ERR "Dict Error\n"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_node {
	unsigned int	key;
	char			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_bucket {
	t_node	*head;
	int		count;
}	t_bucket;

char			*ft_strncpy(char *dest, char *src, int n);
int				ft_str_len(char *str);
int				ft_str_sep_len(char *str, char sep);
char			*ft_trim(char *dest, char *src);
char			*get_str(char *origin_str, int len);
char			**ft_split(char **dest, char *str, char sep);
int				count_word(char *str, char sep);
void			print_err(int type);
unsigned int	ft_atoi(char *str);

char			**key_pairs(char *file_str);
t_bucket		*make_dict(char **key_pairs);
void			show_dict(t_bucket *dict);
t_bucket		*dict_add(unsigned int key, char *value, t_bucket *dict);
int				file_read(char *path, char *buf, int buf_len);
char			**parse_file(char **dest, char *dict_path);
t_node			*createNode(unsigned int key, char *value);
t_node			*find_param(t_bucket *dict, unsigned int key);
int				hashFunction(unsigned int key);

#endif