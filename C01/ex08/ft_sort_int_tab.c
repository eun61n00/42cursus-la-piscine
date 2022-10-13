/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:00:38 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/21 17:37:11 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *tab, int a, int b)
{
	int	tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = size;
	while (i >= 1)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] > tab[j + 1])
				swap(tab, j, j + 1);
			j++;
		}
		i--;
	}
}
