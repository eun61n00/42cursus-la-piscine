/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/25 13:56:21 by eukwon           ###   ########.fr       */
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
	int	i;

	if (argc == 1)
		return (-1);
	a = parsing(argc, argv);
	b = (t_double_linked_list *)malloc(sizeof(t_double_linked_list));
	if (b == NULL)
		return (-1);
	b->size = 0;
	b->head = NULL;
	b->tail = NULL;
	if (a == NULL || contain_duplicates(&a) == 1)
		ft_printf("Error\n");
	else
	{
		sorted_arr = make_sorted_array(&a);
		tmp = a->head;
		i = 0;
		while (tmp && tmp->data == sorted_arr[i])
		{
			tmp = tmp->next;
			i++;
		}
		if (tmp == NULL)
			return (-1); // already sorted
		i = 0;
		a_to_b(a->size, &a, &b, sorted_arr, &i);
		tmp = a->head;
		for (int i = 0; i < a->size; i++)
		{
			ft_printf("%d ", tmp->data);
			tmp = tmp->next;
		}
		free(sorted_arr);
	}
	if (a)
	{
		tmp = a->head;
		while(tmp)
		{
			free(tmp);
			tmp = tmp->next;
		}
		free(a);
	}
	tmp = b->head;
	while(tmp)
	{
		tmp = tmp->next;
		free(tmp);
	}
	free(b);
	return (0);
}
