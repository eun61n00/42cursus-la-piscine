/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:34:52 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/01 16:38:56 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*init_variables(int n)
{
	int	*variables_array;

	variables_array = (int *)malloc(sizeof(int) * 5);
	variables_array[0] = 0;
	variables_array[1] = 0;
	variables_array[2] = 0;
	variables_array[3] = n / 3;
	variables_array[4] = n / 3 * 2;
	return (variables_array);
}
