/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 08:17:57 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/22 15:53:07 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	params_idx;

	params_idx = 1;
	while (params_idx < argc)
	{
		ft_putstr(argv[params_idx]);
		write(1, "\n", 1);
		params_idx++;
	}
}
