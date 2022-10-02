/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:05:45 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/02 20:30:10 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	already_sorted(t_double_linked_list **a, int n)
{
	t_double_linked_list_node	*tmp;

	tmp = (*a)->head;
	while (n > 1)
	{
		if (tmp->data > tmp->next->data)
			return (0);

		tmp = tmp->next;
		n--;
	}
	return (1);
}

int	already_sorted_reverse(t_double_linked_list **b, int n)
{
	t_double_linked_list_node	*tmp;

	tmp = (*b)->head;
	while (n > 1)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
		n--;
	}
	return (1);
}
