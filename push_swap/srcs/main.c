/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/05 15:23:22 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	test(t_num_stack *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->data);
		stack = stack->next;
	}
	ft_printf("\n");
}

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
	test_stack = a;
	test(test_stack);

	pb(&a, &b);
	test_stack = b;
	test(test_stack);

	pa(&a, &b);
	test_stack = a;
	test(test_stack);
	return (0);
}
