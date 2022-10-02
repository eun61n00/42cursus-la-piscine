/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/02 09:01:12 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	already_sorted(t_double_linked_list **a, int *sorted_array)
{
	t_double_linked_list_node	*tmp;
	int							i;

	tmp = (*a)->head;
	i = 0;
	while (tmp && (tmp->data == sorted_array[i]))
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL)
		return (1);
	return (0);
}

static void	free_list(t_double_linked_list **a, t_double_linked_list **b)
{
	t_double_linked_list_node	*tmp;

	if (*a)
	{
		tmp = (*a)->head;
		while (tmp)
		{
			free(tmp);
			tmp = tmp->next;
		}
		free(*a);
	}
	tmp = (*b)->head;
	while (tmp)
	{
		tmp = tmp->next;
		free(tmp);
	}
	free(*b);
}

int	main(int argc, char *argv[])
{
	t_double_linked_list		*a;
	t_double_linked_list		*b;
	int							*sorted_array;

	if (argc == 1)
		return (-1);
	a = parsing(argc, argv);
	b = new_double_linked_list();
	if (b == NULL)
		return (-1);
	if (a == NULL || contain_duplicates(&a) == 1)
		ft_printf("Error\n");
	else
	{
		sorted_array = make_sorted_array(&a);
		if (already_sorted(&a, sorted_array) == 1)
			return (0);
		a_to_b(a->size, &a, &b, sorted_array);
		free(sorted_array);
	}
	free_list(&a, &b);
	return (0);
}
