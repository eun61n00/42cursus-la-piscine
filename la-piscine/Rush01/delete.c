/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjch <youngjch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:13:53 by youngjch          #+#    #+#             */
/*   Updated: 2022/01/16 17:19:15 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"

void	del_fix_r_b(int (*return_map)[4], int target_number, int input_index)
{
	int	row;
	int	col;
	int	repeat_time;
	int	init_row;
	int	init_col;

	row = input_index / 4;
	col = input_index % 4;
	init_row = row;
	init_col = col;
	while ((row - 1) * 4 + 2 >= 0)
	{
		repeat_time = 0;
		while (repeat_time < 4)
		{
			if (return_map[((row - 1) * 4) + col][repeat_time] == target_number)
				return_map[((row - 1) * 4) + col][repeat_time] = -1;
			repeat_time++;
		}
		row--;
	}
}

void	del_fix_r_f(int (*return_map)[4], int target_number, int input_index)
{
	int	row;
	int	col;
	int	repeat_time;
	int	init_row;
	int	init_col;

	row = input_index / 4;
	col = input_index % 4;
	init_row = row;
	init_col = col;
	while ((row + 1) * 4 + 2 <= 15)
	{
		repeat_time = 0;
		while (repeat_time < 4)
		{
			if (return_map[((row + 1) * 4) + col][repeat_time] == target_number)
				return_map[((row + 1) * 4) + col][repeat_time] = -1;
			repeat_time++;
		}
		row++;
	}
}

void	del_fix_c_u(int (*return_map)[4], int target_number, int input_index)
{
	int	row;
	int	col;
	int	repeat_time;
	int	init_row;
	int	init_col;

	row = input_index / 4;
	col = input_index % 4;
	init_row = row;
	init_col = col;
	while (row * 4 + col - 1 >= init_row * 4)
	{
		repeat_time = 0;
		while (repeat_time < 4)
		{
			if (return_map[row * 4 + col - 1][repeat_time] == target_number)
				return_map[row * 4 + col - 1][repeat_time] = -1;
			repeat_time++;
		}
		col--;
	}
}

void	del_fix_c_d(int (*return_map)[4], int target_number, int input_index)
{
	int	row;
	int	col;
	int	repeat_time;
	int	init_row;
	int	init_col;

	row = input_index / 4;
	col = input_index % 4;
	init_row = row;
	init_col = col;
	while (row * 4 + col + 1 <= init_row * 4 + 3)
	{
		repeat_time = 0;
		while (repeat_time < 4)
		{
			if (return_map[row * 4 + col + 1][repeat_time] == target_number)
				return_map[row * 4 + col + 1][repeat_time] = -1;
			repeat_time++;
		}
		col++;
	}
}
