#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd, fd2;
	char	*file_dir = "test1";
	char 	*file_dir2 = "test2";
	char	*ret;

	fd = open(file_dir, O_RDONLY);
	fd2 = open(file_dir2, O_RDONLY);

	for (int i = 0; i < 3; i++)
	{
		ret = get_next_line(fd);
		printf("%s", ret);
		free(ret);
		ret = get_next_line(fd2);
		printf("%s", ret);
		free(ret);
	}
}
