/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:29:25 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/21 17:36:50 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	//int	mid;
	int	tmp;

	i = 0;
	//if (size % 2 == 0)
	//	mid = size / 2;
	//else
	//	mid = size / 2 + 1;
	while (i <= size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i + 1];
		tab[size - i + 1] = tmp;
		i++;
	}
	int	idx = 0;
	while (idx < size)
	{
		printf("%d", tab[idx]);
		idx++;
	}
}
