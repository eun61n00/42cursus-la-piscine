/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:55:25 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/24 09:58:55 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else
	{
		if (nb / 10 > 0)
			ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

int	main(void)
{
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(-38272);
	write(1, "\n", 1);
	ft_putnbr(10384);
}
