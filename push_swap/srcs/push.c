/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:37:45 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/04 10:54:49 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_num_stack **a, t_num_stack **b)
{
	t_num_stack *tmp;
	t_num_stack *tmp2;

	if ((*b) == NULL)
		return;
	if ((*a) == NULL)
	{
		(*a) = (*b);
		(*a)->next = NULL;
		return;
	}
	else
	{
		tmp = (*b)->next;
		tmp2 = (*a);
		(*a) = (*b);
		(*b) = tmp;
		(*a)->next = tmp2;
	}
}

void	pb(t_num_stack **a, t_num_stack **b)
{
	t_num_stack *tmp;
	t_num_stack *tmp2;

	if ((*a) == NULL)
		return;
	if ((*b) == NULL)
	{
		(*b) = (*a);
		(*b)->next = NULL;
		return;
	}
	else
	{
		tmp = (*a)->next;
		tmp2 = (*b);
		(*b) = (*a);
		(*a) = tmp;
		(*b)->next = tmp2;
	}
}