/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/25 09:52:55 by eukwon           ###   ########.fr       */
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
	// atexit(check_leaks);
	// system("leads push_swap");
	t_double_linked_list *a;
	t_double_linked_list *b;
	t_double_linked_list_node *tmp;
	int	*sorted_arr;

	if (argc == 1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	// check error
	// if (check_err(argc, argv) == -1)
	// {
	// 	ft_printf("Error\n");
	// 	return (-1);
	// }

	// parsing
	a = parsing(argc, argv);
	b = (t_double_linked_list *)malloc(sizeof(t_double_linked_list));
	if (b == NULL)
		return (-1);
	b->size = 0;
	b->head = NULL;
	b->tail = NULL;

	sorted_arr = make_sorted_array(&a);
	a_to_b(a->size, &a, &b, sorted_arr);
	// tmp = a->head;
	// for (int i = 0; i < a->size; i++)
	// {
	// 	ft_printf("%d ", tmp->data);
	// 	tmp = tmp->next;
	// }
	tmp = a->head;
	while(tmp)
	{
	free(tmp);
	tmp = tmp->next;
	}
	free(a);
	tmp = b->head;
	while(tmp)
	{
	tmp = tmp->next;
	free(tmp);
	}
	free(b);
	free(sorted_arr);
	return (0);
}
