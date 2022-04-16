/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:15:48 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/18 20:16:01 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

unsigned int	to_unsigned_int(int nbr)
{
	unsigned int	nbr_u;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_u = nbr * (-1);
	}
	else
		nbr_u = nbr;
	return (nbr_u);
}

void	write_nbr(unsigned int nbr_u, char *base, int base_num)
{
	if (nbr_u / base_num != 0)
	{
		write_nbr(nbr_u / base_num, base, base_num);
		write(1, &base[nbr_u % base_num], 1);
	}
	else
	{
		write(1, &base[nbr_u], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_num;
	unsigned int	nbr_u;

	base_num = 0;
	if (check_base(base) == 0)
		return ;
	nbr_u = to_unsigned_int(nbr);
	while (base[base_num])
		base_num++;
	write_nbr(nbr_u, base, base_num);
}
