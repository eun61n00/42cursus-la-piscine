/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:50:28 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/19 22:12:37 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_unsorted(t_double_linked_list **a, t_double_linked_list **b, int ra_cnt, int rb_cnt)
{
	while (ra_cnt > 0 && rb_cnt)
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
	while (rb_cnt > 0)
	{
		rrb(b);
		rb_cnt--;
	}
}

void	a_to_b(int n, t_double_linked_list **a, t_double_linked_list **b, int *sorted_array)
{
	int	pivot1_idx, pivot2_idx;
	int	ra_cnt = 0, rb_cnt = 0, pb_cnt = 0;

	if (n <= 3)
	{
		sort_few_nums(a);
		while (n > 0)
		{
			pb(a, b);
			n--;
		}
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
	reverse_unsorted(a, b, ra_cnt, rb_cnt);
	a_to_b(ra_cnt, a, b, &sorted_array[pivot2_idx]);
	b_to_a(rb_cnt, a, b, &sorted_array[pivot1_idx]);
	b_to_a(pb_cnt - rb_cnt, a, b, sorted_array);
}

void	b_to_a(int n, t_double_linked_list **a, t_double_linked_list **b, int *sorted_array)
{
	int pivot1_idx, pivot2_idx;
	int ra_cnt = 0, pa_cnt = 0, rb_cnt = 0;

	if (n <= 3)
	{
		sort_few_nums(b);
		while (n > 0)
		{
			pa(a, b);
			n--;
		}
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
	reverse_unsorted(a, b, ra_cnt, rb_cnt);
	a_to_b(pa_cnt - ra_cnt, a, b, sorted_array);
	a_to_b(rb_cnt, a, b, sorted_array);
	b_to_a(ra_cnt, a, b, sorted_array);
}

void	sort_few_nums(t_double_linked_list **list)
{
	int top;
	int mid;
	int bottom;

	top = (*list)->head->data;
	bottom = (*list)->tail->data;
	if ((*list)->size == 1)
		return ;
	else if ((*list)->size == 2)
	{
		if (top > bottom)
			sa(list);
		return ;
	}
	mid = (*list)->head->next->data;
	if (top < mid < bottom)
		return ;
	if ((top > mid && top < bottom)
		|| (top > mid && mid > bottom)
		|| (top < bottom && bottom < mid))
	{
		sa(list);
		sort_few_nums(list);
	}
	else if (top > bottom && mid < bottom)
		ra(list);
	else
		rra(list);
}