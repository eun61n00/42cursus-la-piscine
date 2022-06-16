/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:46:24 by eukwon            #+#    #+#             */
/*   Updated: 2022/06/16 16:33:33 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_nbr(int n)
{
	char mod;
	char nb_char;

	if (n / 10)
	{
		ft_putnbr(n / 10);
		mod = n % 10 + '0';
		write(1, &mod, 1);
	}
}

void ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		write_nbr(-n);
	}
	else
		write_nbr(n);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	while(*str)
	{
		i++;
		str++;
	}

	return i;
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}