/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:59:07 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/22 16:16:33 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	while (n <= nb / n)
	{
		if (n * n == nb)
			return (n);
		n++;
	}
	return (n - 1);
}

int	ft_is_prime(int nb)
{
	int	nb_sqrt;

	if (nb == 0 || nb == 1)
		return (0);
	nb_sqrt = ft_sqrt(nb);
	while (nb_sqrt > 1)
	{
		if (nb % nb_sqrt == 0)
			return (0);
		nb_sqrt--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		return (2);
	while (ft_is_prime(nb) == 0)
	{
		nb++;
	}
	return (nb);
}
