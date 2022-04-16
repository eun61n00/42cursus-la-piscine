/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:31:23 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/22 16:24:44 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(int idx, int val, char *puzzle)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (puzzle[i] - '0' == val)
			return (0);
		if (puzzle[i] - '0' - val == i - idx)
			return (0);
		if (puzzle[i] - '0' - val == idx - i)
			return (0);
		i++;
	}
	return (1);
}

void	solve_queens(int idx, char *puzzle, int *cnt)
{
	int	val;

	if (idx == 10)
	{
		write(1, puzzle, 10);
		write(1, "\n", 1);
		*cnt = *cnt + 1;
	}
	val = 0;
	while (val < 10)
	{
		puzzle[idx] = val + '0';
		if (is_valid(idx, val, puzzle))
		{
			solve_queens(idx + 1, puzzle, cnt);
		}
		val++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	puzzle[11];
	int		idx;
	int		cnt;

	idx = 0;
	cnt = 0;
	while (idx < 11)
	{
		puzzle[idx] = '\0';
		idx++;
	}
	idx = 0;
	solve_queens(idx, puzzle, &cnt);
	return (cnt);
}
