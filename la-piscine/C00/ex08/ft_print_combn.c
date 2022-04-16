/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:13:15 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/16 00:26:58 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
int		check_comb(char *comb, int n);

int	check_comb(char *comb, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (comb[i] >= comb[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	re_comb(char *comb, int n)
{
	int	i;

	i = n - 1;
	while (i > 0)
	{
		if (comb[i] > '9')
		{
			comb[i - 1]++;
			comb[i] = '0';
		}
		i--;
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int		i;
	char	comb[10];

	i = 0;
	while (i < n)
	{
		comb[i] = i + '0';
		i++;
	}
	while (i < 10)
	{
		comb[i] = '\0';
		i++;
	}
	while (comb[0] <= 10 - n + '0')
	{
		if (check_comb(comb, n) == 1)
		{
			write(1, comb, 10);
			if (comb[0] != 10 - n + '0')
				write(1, ", ", 2);
		}
		comb[n - 1]++;
		re_comb(comb, n);
	}
}
