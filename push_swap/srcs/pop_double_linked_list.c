/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_double_linked_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:48:16 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/30 11:03:46 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_double_linked_list_node	*pop_first_node(t_double_linked_list **list)
{
	t_double_linked_list_node	*tmp;

	tmp = (*list)->head;
	(*list)->head = tmp->next;
	if ((*list)->head)
		(*list)->head->prev = NULL;
	else
		(*list)->tail = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	(*list)->size -= 1;
	return (tmp);
}

static t_double_linked_list_node	*pop_last_node(t_double_linked_list **list)
{
	t_double_linked_list_node	*tmp;

	tmp = (*list)->tail;
	(*list)->tail = (*list)->tail->prev;
	if ((*list)->size == 1)
		(*list)->head = NULL;
	else
		(*list)->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	(*list)->size -= 1;
	return (tmp);
}

t_double_linked_list_node	*pop(t_double_linked_list **list, int node_idx)
{
	t_double_linked_list_node	*tmp;

	tmp = (*list)->head;
	if (!((*list)->head))
		return (NULL);
	if (node_idx == 0)
		return (pop_first_node(list));
	else if (node_idx == ((*list)->size - 1) || node_idx == -1)
		return (pop_last_node(list));
	else
	{
		while (node_idx > 0)
		{
			tmp = tmp->next;
			node_idx--;
		}
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	(*list)->size -= 1;
	return (tmp);
}
