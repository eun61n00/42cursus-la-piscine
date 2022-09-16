/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/17 00:46:01 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

void	check_leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char *argv[])
{
	atexit(check_leaks);
	t_double_linked_list *a;
	t_double_linked_list *b;
	int	*sorted_arr;

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
	b->size = 0;
	b->head = NULL;
	b->tail = NULL;

	sorted_arr = make_sorted_array(&a);
	a_to_b(a->size, &a, &b, sorted_arr);

	return (0);
}
