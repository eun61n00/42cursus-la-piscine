/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:55:39 by junsoh            #+#    #+#             */
/*   Updated: 2022/01/23 20:30:50 by junsoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom.h"

void	print_err(int type)
{
	if (type == -1)
		write(1, COM_ERR, ft_str_len(COM_ERR));
	else if (type == -2)
	{
		write(1, DICT_ERR, ft_str_len(DICT_ERR));
	}
}
