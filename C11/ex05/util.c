/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:49:50 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/27 15:37:14 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (is_numeric(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nbr);
	}
	else
	{
		if (nbr / 10 > 0)
			ft_putnbr(nbr / 10);
		c = nbr % 10 + '0';
		write(1, &c, 1);
	}
}
