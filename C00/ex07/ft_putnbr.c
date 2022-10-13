/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:18:09 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/10 09:34:21 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int				cnt;
	char			arr[20];
	unsigned int	nb_unsigned;

	cnt = 19;
	if (nb < 0)
	{
		nb_unsigned = nb * (-1);
		write(1, "-", 1);
	}
	else if (nb == 0)
	{
		nb_unsigned = 0;
		arr[0] = '0';
	}
	else
		nb_unsigned = nb;
	while (nb_unsigned != 0)
	{
		arr[cnt] = (nb_unsigned % 10) + '0';
		cnt --;
		nb_unsigned /= 10;
	}
	write(1, arr, 20);
}
