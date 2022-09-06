/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/06 12:58:28 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	main(int argc, char *argv[])
{
	t_num_stack *a;
	t_num_stack *b;
	t_num_stack *test_stack;


	// check error
	if (check_err(argc, argv) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}

	// parsing
	a = parsing(argv);
	b = (t_num_stack *)malloc(sizeof(t_num_stack));
	if (b == NULL)
		return (-1);
	b->data = -1;
	b->next = NULL;

	sa(&a);
	pb(&a, &b);
	pa(&a, &b);
	ra(&a);
	return (0);
}
