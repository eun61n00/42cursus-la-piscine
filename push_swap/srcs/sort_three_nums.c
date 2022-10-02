/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:59:34 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/02 09:34:16 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_order(t_double_linked_list **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->head->data;
	middle = (*a)->head->next->data;
	bottom = (*a)->head->next->next->data;
	if ((top < middle) && (middle < bottom))
		return (0);
	else if ((top > middle && top < bottom)
		|| (top > middle && middle > bottom)
		|| (top < bottom && bottom < middle))
		return (1);
	else if (top > bottom && middle < bottom)
	{
		if ((*a)->size <= 3)
			return (2);
		return (3);
	}
	else
	{
		if ((*a)->size <= 3)
			return (4);
		return (5);
	}
}

static void	rotate_three_nums(t_double_linked_list **a, \
								t_double_linked_list **b)
{
	ra(a);
	pb(a, b);
	pb(a, b);
	rra(a);
	pa(a, b);
	pa(a, b);
}

static void	reverse_rotate_three_nums(t_double_linked_list **a, \
										t_double_linked_list **b)
{
	pb(a, b);
	pb(a, b);
	ra(a);
	pa(a, b);
	pa(a, b);
	rra(a);
}

static void	sort_three_nums(t_double_linked_list **a, \
								t_double_linked_list **b, int n)
{
	int	order_res;

	order_res = check_order(a);
	if (order_res == 0)
		return ;
	else if (order_res == 1)
	{
		sa(a);
		sort_few_nums(a, b, n);
	}
	else if (order_res == 2)
		ra(a);
	else if (order_res == 3)
		rotate_three_nums(a, b);
	else if (order_res == 4)
		rra(a);
	else
		reverse_rotate_three_nums(a, b);
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
	else
		sort_three_nums(a, b, n);
}
