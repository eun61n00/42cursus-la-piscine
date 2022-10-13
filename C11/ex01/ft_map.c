/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:42:49 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/26 14:46:28 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*res_arr;

	i = 0;
	res_arr = (int*)malloc(sizeof(int) * length);
	while (i < length)
	{
		res_arr[i] = f(tab[i]);
		i++;
	}
}
