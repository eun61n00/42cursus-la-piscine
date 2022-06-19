/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:33:28 by eukwon            #+#    #+#             */
/*   Updated: 2022/06/19 15:28:42 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(const char *str)
{
	int	ret;

	ret = 0;
	if (str == NULL)
	{
		ft_putstr_pf("(null)");
		return (6);
	}
	while (*str)
	{
		ft_putchar_pf(*str++);
		ret++;
	}
	return (ret);
}
