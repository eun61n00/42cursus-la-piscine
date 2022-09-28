/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_double_linked_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:51:50 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/28 15:47:48 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_double_linked_list(t_double_linked_list **list, \
								t_double_linked_list_node *new_node)
{
	if ((*list)->head)
	{
		new_node->next = (*list)->head;
		(*list)->head->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
		(*list)->tail = new_node;
	}
	(*list)->head = new_node;
	(*list)->size += 1;
}
