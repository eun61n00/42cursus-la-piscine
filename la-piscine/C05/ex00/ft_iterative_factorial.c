/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:31:09 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/22 09:19:09 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	unsigned long long int	result;

	result = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		result *= nb;
		nb--;
	}
	return (result);
}
