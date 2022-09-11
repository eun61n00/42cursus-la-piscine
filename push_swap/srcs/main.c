/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/11 16:39:59 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	main(int argc, char *argv[])
{
	t_double_linked_list *a;
	t_double_linked_list *b;


	// check error
	if (check_err(argc, argv) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}

	// parsing
	a = parsing(argv);
	b = (t_double_linked_list *)malloc(sizeof(t_double_linked_list));
	if (b == NULL)
		return (-1);
	t_double_linked_list_node *b_node = new_double_linked_list_node(0);
	b->size = 1;
	b->head = b_node;
	b->tail = b_node;

	// sa(&a);
	// sb(&b);
	// pa(&a, &b);
	// ra(&a);
	indexing(&a);
	return (0);
}
