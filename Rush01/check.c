/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjch <youngjch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:14:01 by youngjch          #+#    #+#             */
/*   Updated: 2022/01/16 17:39:23 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"

void	all_check(int (*return_map)[4])
{
	int	i;
	int	fix_num;
	int	count;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (j < 200)
	{
		while (i < 16)
		{
			fix_num = check_fixed(return_map, i);
			if (fix_num != -1)
			{
				del_fix_r_b(return_map, fix_num, i);
				del_fix_r_f(return_map, fix_num, i);
				del_fix_c_u(return_map, fix_num, i);
				del_fix_c_d(return_map, fix_num, i);
				count++;
			}
			i++;
		}
		j++;
	}
}

int	check_fixed(int (*return_map)[4], int input_index)
{
	int	i;
	int	minus_count;

	i = 0;
	minus_count = 0;
	while (i < 4)
	{
		if (return_map[input_index][i] == -1)
			minus_count++;
		i++;
	}
	i = 0;
	if (minus_count == 3)
	{
		while (i < 4)
		{
			if (return_map[input_index][i] != -1)
				return (return_map[input_index][i]);
			i++;
		}
	}
	return (-1);
}
