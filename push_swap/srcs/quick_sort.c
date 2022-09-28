/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:50:28 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/28 14:08:21 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_idx_in_sorted_array(int find_num, int *sorted_array) {
	int idx;

	idx = 0;
	while (*sorted_array)
	{
		if (find_num == *sorted_array)
			return (idx);
		idx++;
		sorted_array++;
	}
	return (-1);
}

void	reverse_unsorted(t_double_linked_list **a, t_double_linked_list **b, int ra_cnt, int rb_cnt, int *i)
{
	if (*i == 1)
	{
		while (ra_cnt > 0 && rb_cnt > 0)
		{
			rrr(a, b);
			ra_cnt--;
			rb_cnt--;
		}
		while (ra_cnt > 0)
		{
			rra(a);
			ra_cnt--;
		}
	}
	while (rb_cnt > 0)
	{
		rrb(b);
		rb_cnt--;
	}
}

void	a_to_b(int n, t_double_linked_list **a, t_double_linked_list **b, int *sorted_array, int *i)
{
	int	pivot1_idx, pivot2_idx;
	int	ra_cnt = 0, rb_cnt = 0, pb_cnt = 0;

	if (n <= 3)
	{
		sort_few_nums(a, b, n);
		return ;
	}
	pivot1_idx = n/3;
	pivot2_idx = n/3*2;

	while (n > 0)
	{
		if ((*a)->head->data >= sorted_array[pivot2_idx])
		{
			ra(a);
			ra_cnt++;
		}
		else
		{
			pb(a, b);
			pb_cnt++;
			if ((*b)->head->data >= sorted_array[pivot1_idx])
			{
				rb(b);
				rb_cnt++;
			}
		}
		n--;
	}
	reverse_unsorted(a, b, ra_cnt, rb_cnt, i);
	a_to_b(ra_cnt, a, b, &sorted_array[pivot2_idx], i);
	b_to_a(rb_cnt, a, b, &sorted_array[pivot1_idx], i);
	b_to_a(pb_cnt - rb_cnt, a, b, sorted_array, i);
}

void	b_to_a(int n, t_double_linked_list **a, t_double_linked_list **b, int *sorted_array, int *i)
{
	int pivot1_idx, pivot2_idx;
	int ra_cnt = 0, pa_cnt = 0, rb_cnt = 0;
	int n_cp;

	*i = 0;
	n_cp = n;
	if (n <= 3)
	{
		while (n > 0)
		{
			pa(a, b);
			n--;
		}
		n = n_cp;
		sort_few_nums(a, b, n);
		return ;
	}
	pivot1_idx = n/3;
	pivot2_idx = n/3*2;
	while (n > 0)
	{
		if ((*b)->head->data < sorted_array[pivot1_idx])
		{
			rb(b);
			rb_cnt++;
		}
		else
		{
			pa(a, b);
			pa_cnt++;
			if ((*a)->head->data < sorted_array[pivot2_idx])
			{
				ra(a);
				ra_cnt++;
			}
		}
		n--;
	}
	a_to_b(pa_cnt-ra_cnt, a, b, &sorted_array[pivot2_idx], i);
	reverse_unsorted(a, b, ra_cnt, rb_cnt, i);
	a_to_b(ra_cnt, a, b, &sorted_array[pivot1_idx], i);
	b_to_a(rb_cnt, a, b, sorted_array, i);
}

void	sort_few_nums(t_double_linked_list **a, t_double_linked_list **b, int n)
{
	int top;
	int middle;
	int bottom;


	if (n == 1)
		return ;
	else if (n == 2)
	{
		if ((*a)->head->data > (*a)->head->next->data)
			sa(a);
		return ;
	}
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
