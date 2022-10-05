/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 07:32:35 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/05 09:30:14 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free_double_pointer(char **double_pointer)
{
	int	i;

	i = 0;
	while (double_pointer[i])
	{
		free(double_pointer[i]);
		i++;
	}
	free(double_pointer);
}
