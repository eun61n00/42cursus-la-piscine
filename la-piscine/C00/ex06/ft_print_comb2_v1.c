/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:54:19 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/08 15:18:57 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

int	main(void)
{
	ft_print_comb2();
	return (1);
}

void	ft_print_comb2(void)
{
	char	comb[7];
	int	test;
	comb[0] = '0';
	comb[2] = ' ';
	comb[5] = ',';
	comb[6] = ' ';
	while (comb[0] <= '9')
	{
		comb[1] = '0';
		while (comb[1] <= '9')
		{
			comb[3] = comb[0];
			if (comb[1] == '9')
			{
				comb[3] = comb[0] + 1;
				comb[4] = '0';
			}
			else
			{
				comb[4] = comb[1] + 1;
			}
			while (comb[3] <= '9')
			{
				while (comb[4] <= '9')
				{
					write(1, &test, 7);
					comb[4]++;
				}
				comb[3]++;
			}
			comb[1]++;
		}
		comb[0]++;
		write(1, "\n", 1);
	}
}
