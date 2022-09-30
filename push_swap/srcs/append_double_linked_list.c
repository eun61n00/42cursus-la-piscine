/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_double_linked_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:17:39 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/30 11:03:54 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append_double_linked_list(t_double_linked_list **list, \
									t_double_linked_list_node *new_node)
{
	if ((*list)->head)
	{
		new_node->prev = (*list)->tail;
		(*list)->tail->next = new_node;
		(*list)->tail = new_node;
	}
	else
	{
		(*list)->head = new_node;
		(*list)->tail = new_node;
	}
	(*list)->size += 1;
}
