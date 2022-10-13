/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjch <youngjch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:14:13 by youngjch          #+#    #+#             */
/*   Updated: 2022/01/16 17:39:35 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

int	main(int argc, char **argv)
{
	char	*input_array;
	int		return_map[16][4];
	int		input_values[16];
	int		i;
	int		j;

	input_array = argv[1];
	i = 0;
	j = 0;
	while (*input_array != '\0')
	{
		if (*input_array >= '0' && *input_array <= '9')
		{
			input_values[i] = *input_array - '0';
			i++;
		}
		input_array++;
	}
	if (argc == 2)
	{
		rush(input_values, return_map, 4);
	}
	return (0);
}
