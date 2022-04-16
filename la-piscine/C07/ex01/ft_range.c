/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:36:15 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/26 00:06:15 by eukwon           ###   ########.fr       */
/*   Updated: 2022/01/26 10:04:36 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	idx;

	if (min >= max)
		return (NULL);
	array = (int *)malloc(sizeof(int) * (max - min));
	if (!array)
		return (NULL);
	idx = 0;
	while (min < max)
	{
		array[idx] = min;
		min++;
		idx++;
	}
	return (array);
}