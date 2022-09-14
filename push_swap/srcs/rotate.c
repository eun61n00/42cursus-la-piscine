/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:37:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/14 13:48:05 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_double_linked_list **a)
{
	t_double_linked_list_node *popped_node;

	popped_node = pop(a, 0);
	append_double_linked_list(a, popped_node);
	ft_printf("ra\n");
}

void	rra(t_double_linked_list **a)
{
	add_double_linked_list(a, pop(a, -1));
	ft_printf("rra\n");
	// TODO impletment rra
}

void	rb(t_double_linked_list **b)
{
	t_double_linked_list_node *popped_node;

	popped_node = pop(b, 0);
	append_double_linked_list(b, popped_node);
	ft_printf("rb\n");
}

void	rrb(t_double_linked_list **b)
{
	add_double_linked_list(b, pop(b, -1));
	ft_printf("rrb\n");
}

void	rrr(t_double_linked_list **a, t_double_linked_list **b)
{
	t_double_linked_list_node *popped_node;

	popped_node = pop(a, 0);
	append_double_linked_list(a, popped_node);
	popped_node = pop(b, 0);
	append_double_linked_list(b, popped_node);
	ft_printf("rrr\n");
}