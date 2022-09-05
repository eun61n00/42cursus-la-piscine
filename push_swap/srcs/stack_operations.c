/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:17:39 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/04 09:50:54 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_num_stack	*new_stack(int data)
{
	t_num_stack *stack;

	stack = (t_num_stack *)malloc(sizeof(t_num_stack));
	if (stack == NULL)
		return NULL;
	stack->data = data;
	stack->next = NULL;
	return (stack);
}

t_num_stack *get_tail(t_num_stack *stack)
{
	t_num_stack *tmp;

	tmp = stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	add_tail(t_num_stack **stack, t_num_stack *new_stack)
{
	if (*stack == 0)
		*stack = new_stack;
	else
		get_tail(*stack)->next = new_stack;
}