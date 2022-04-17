#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd, fd_2;
	char	*file_dir = "test";
	char 	*file_dir2 = "test2";

	fd = open(file_dir, O_RDONLY);
	fd_2 = open(file_dir2, O_RDONLY);

	for (int i = 0; i < 10; i++)
	{
		printf("%s", get_next_line(fd));
		//printf("%s", get_next_line(fd_2));
		//puts("==============");
	}
}
