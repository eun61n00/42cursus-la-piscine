/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/05 09:48:28 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_double_linked_list(t_double_linked_list **list)
{
	t_double_linked_list_node	*tmp;

	if (*list)
	{
		tmp = (*list)->head;
		while (tmp)
		{
			free(tmp);
			tmp = tmp->next;
		}
	}
	free(*list);
}

int	main(int argc, char *argv[])
{
	t_double_linked_list		*a;
	t_double_linked_list		*b;
	int							*sorted_array;

	if (argc == 1)
		return (-1);
	a = parsing(argv);
	b = new_double_linked_list();
	if (b == NULL)
		return (-1);
	if (a == NULL || contain_duplicates(&a) == 1)
		ft_printf("Error\n");
	else
	{
		sorted_array = make_sorted_array(&a);
		if (already_sorted(&a, a->size) == 1)
			return (0);
		a_to_b(a->size, &a, &b, sorted_array);
		free(sorted_array);
	}
	free_double_linked_list(&a);
	free_double_linked_list(&b);
	return (0);
}
