/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjch <youngjch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:14:33 by youngjch          #+#    #+#             */
/*   Updated: 2022/01/16 17:38:51 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "rush01.h"

void	del_val(int (*return_map)[4], int input_val, int dst, int input_index)
{
	int	d;
	int	compare_answer;

	d = 0;
	if (input_val == 4)
	{
		while (d < 4)
		{
			if (return_map[input_index][d] != dst + 1)
			{
				return_map[input_index][d] = -1;
			}
			d++;
		}
		return ;
	}
	compare_answer = 4 - input_val + 2 + dst;
	while (d < 4)
	{
		if (return_map[input_index][d] >= compare_answer && compare_answer <= 4)
		{
			return_map[input_index][d] = -1;
		}
		d++;
	}
}

void	sol_r(int (*return_map)[4], int input_values[], int input_index, int N)
{
	int	repeat_times;
	int	num;
	int	distance;

	repeat_times = 0;
	distance = 0;
	num = input_values[input_index];
	if (input_index < N)
	{
		while (repeat_times++ < N)
		{
			del_val(return_map, num, distance++, input_index);
			input_index += N;
		}
	}
	else
	{
		input_index += N * 2;
		while (repeat_times++ < N)
		{
			del_val(return_map, num, distance++, input_index);
			input_index -= N;
		}
	}
}

void	sol_c(int (*return_map)[4], int input_values[], int input_index, int N)
{
	int	repeat_times;
	int	num;
	int	distance;

	repeat_times = 0;
	distance = 0;
	num = input_values[input_index];
	if (input_index < 12)
	{
		input_index = (input_index % 4) * 4;
		while (repeat_times++ < N)
		{
			del_val(return_map, num, distance++, input_index);
			input_index++;
		}
	}
	else
	{
		input_index = (input_index % 4) * 4 + 3;
		while (repeat_times++ < N)
		{
			del_val(return_map, num, distance++, input_index);
			input_index--;
		}
	}
}

int	rush(int input_values[], int (*return_map)[4], int N)
{
	int	index;
	int	j;
	int	i;

	index = 0;
	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 4)
		{
			return_map[i][j] = j + 1;
			j++;
		}
		i++;
	}
	while (index < 16)
	{
		if (index < 8)
			sol_r(return_map, input_values, index, N);
		else
			sol_c(return_map, input_values, index, N);
		index++;
	}
	all_check(return_map);
	return (1);
}
