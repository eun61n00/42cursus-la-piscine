/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/17 12:45:11 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	*num_arr;
	int	*top_a;
	int *top_b;

	if (argc == 1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	i = 0;
	num_arr = (int *)malloc(sizeof(int) * (argc - 1));
	while (argv[i + 1])
	{
		if (ft_isalpha(argv[i + 1][0]))
		{
			ft_printf("Error\n");
			return (-1);
		}
		num_arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	top_a = swap(&num_arr[argc - 2]);
	top_b = (int *)malloc((sizeof(int) * 5));
	for (int i = 0; i < 5; i++)
		*top_b++ = i;

	push(top_a, top_b);
	ft_printf("top_a: %d, top_b: %d\n", *top_a, *--top_b);
	return (0);
}
