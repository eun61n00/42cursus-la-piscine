/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_double_linked_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:42:27 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/30 10:54:35 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

t_double_linked_list_node	*new_double_linked_list_node(int data)
{
	t_double_linked_list_node	*node;

	node = (t_double_linked_list_node *) \
		malloc(sizeof(t_double_linked_list_node));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->data = data;
	node->next = NULL;
	return (node);
}

t_double_linked_list	*new_double_linked_list(void)
{
	t_double_linked_list	*list;

	list = (t_double_linked_list *) \
		malloc(sizeof(t_double_linked_list));
	if (list == NULL)
		return (NULL);
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->excuted = 0;
	return (list);
}
