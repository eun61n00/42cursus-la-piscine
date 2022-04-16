/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:33:27 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/21 09:24:29 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_nbr_recur(unsigned int nb)
{
	char	mod;
	char	nb_char;

	if (nb / 10 != 0)
	{
		write_nbr_recur(nb / 10);
		mod = nb % 10 + '0';
		write(1, &mod, 1);
	}
	else
	{
		nb_char = nb + '0';
		write(1, &nb_char, 1);
	}
	return ;
}

void	ft_putnbr(int nb)
{
	unsigned int	nb_unsigned;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ub_unsigned = nb * (-1);
		write_nbr_recur(nb_unsigned);
	}
	else if (nb > 0)
	{
		ub_unsigned = nb;
		write_nbr_recur(nb_unsigned);
	}
	else
		write(1, "0", 1);
}
