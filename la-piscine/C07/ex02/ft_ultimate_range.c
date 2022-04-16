/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:22:59 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/28 08:23:43 by eukwon           ###   ########.fr       */
/*   Updated: 2022/01/26 15:42:50 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	range_size;
	int	idx;

	if (min >= max)
	{
		*range = 0;
		return (-1);
	}
	range_size = max - min;
	*range = (int *)malloc(sizeof(int) * (range_size));
	if (*range == 0)
		return (NULL);
	idx = 0;
	while (min < max)
	{
		(*range)[idx] = min;
		min++;
		idx++;
	}
	return (range_size);
}
