/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:53:25 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/26 15:05:10 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	f = is_sort;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) == -1)
			retrn (0);
		i++;
	}
	return (1);
}

int	is_sort(int a, int b)
{
	if (a < b)
		return (-1);
	else if (a == b)
		return (0);
	else
		return (1);
}
