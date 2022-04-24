/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:39:38 by eukwon            #+#    #+#             */
/*   Updated: 2022/04/23 11:57:31 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include "stdio.h"

int	main(void)
{
	int		fd;
	int		fd2;
	char	*file_dir = "./gnlTester/files/41_no_nl";
	char	*file_dir2 = "test1";
	char	*ret;

	fd = open(file_dir, O_RDONLY);
	fd2 = open(file_dir2, O_RDONLY);
	for (int i = 0; i < 10; i++)
	{
		ret = get_next_line(fd);
		printf("%s", ret);
		free(ret);
	}
}