/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_double_linked_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:50:52 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/28 13:51:07 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_double_linked_list **list, t_double_linked_list_node *node)
{
	t_double_linked_list_node	*tmp;

	if (node == NULL)
		return ;
	if ((*list)->head == NULL)
	{
		(*list)->head = node;
		(*list)->tail = node;
	}
	else
	{
		tmp = (*list)->head;
		(*list)->head = node;
		node->next = tmp;
		tmp->prev = node;
	}
	(*list)->size += 1;
}
