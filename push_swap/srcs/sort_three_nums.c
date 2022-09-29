/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:59:34 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/29 19:04:12 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_nums(t_double_linked_list **a, t_double_linked_list **b, int n)
{
	int top;
	int middle;
	int bottom;

	top = (*a)->head->data;
	middle = (*a)->head->next->data;
	bottom = (*a)->head->next->next->data;
	if ((top < middle) && (middle < bottom))
		return ;
	if ((top > middle && top < bottom)
		|| (top > middle && middle > bottom)
		|| (top < bottom && bottom < middle))
	{
		sa(a);
		sort_few_nums(a, b, n);
	}
	else if (top > bottom && middle < bottom)
	{
		if ((*a)->size <= 3)
		{
			ra(a);
			return ;
		}
		ra(a);
		pb(a, b);
		pb(a,b);
		rra(a);
		pa(a, b);
		pa(a, b);
	}
	else
	{
		if ((*a)->size <= 3)
		{
			rra(a);
			return ;
		}
		pb(a, b);
		pb(a, b);
		ra(a);
		pa(a, b);
		pa(a, b);
		rra(a);
	}
}

void	sort_few_nums(t_double_linked_list **a, t_double_linked_list **b, int n)
{

	if (n == 1)
		return ;
	else if (n == 2)
	{
		if ((*a)->head->data > (*a)->head->next->data)
			sa(a);
		return ;
	}
	else {
		sort_three_nums(a, b, n)
	}
}
