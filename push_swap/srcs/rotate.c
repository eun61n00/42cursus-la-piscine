/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:37:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/11 15:48:47 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_double_linked_list **a)
{
	t_double_linked_list_node *popped_node;

	popped_node = pop(a);
	append_double_linked_list(a, popped_node);
	ft_printf("ra\n");
}

void	rb(t_double_linked_list **b)
{
	t_double_linked_list_node *popped_node;

	popped_node = pop(b);
	append_double_linked_list(b, popped_node);
	ft_printf("b\n");
}