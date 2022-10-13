/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:39:57 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/24 15:21:59 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	else
	{
		if (nbr / 10 > 0)
			ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
