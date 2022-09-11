/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:17:39 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/11 15:43:36 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_double_linked_list_node	*new_double_linked_list_node(int data)
{
	t_double_linked_list_node *node;

	node = (t_double_linked_list_node *)malloc(sizeof(t_double_linked_list_node));
	if (node == NULL)
		return NULL;
	node->prev = NULL;
	node->data = data;
	node->next = NULL;
	return (node);
}

void	append_double_linked_list(t_double_linked_list **list, t_double_linked_list_node *new_node)
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

void	add_double_linked_list(t_double_linked_list **list, t_double_linked_list_node *new_node)
{
	if (*list)
		new_node->next = (*list)->head;
	else
		new_node->next = NULL;
	(*list)->head = new_node;
	(*list)->size += 1;
}

t_double_linked_list_node *pop(t_double_linked_list **list)
{
	t_double_linked_list_node *tmp;

	tmp = (*list)->head;
	if (!tmp)
		return NULL;
	(*list)->head = tmp->next; //두 번째 노드가 없으면 null
	if ((*list)->head)
		(*list)->head->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	push(t_double_linked_list **list, t_double_linked_list_node *node)
{
	t_double_linked_list_node *tmp;

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