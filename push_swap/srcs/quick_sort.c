// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   quick_sort.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/09/12 09:50:28 by eukwon            #+#    #+#             */
// /*   Updated: 2022/09/14 08:42:32 by eukwon           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

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
		return ; //insertion sort
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
	int pivot1, pivot2;
	int ra_cnt = 0, pa_cnt = 0, rb_cnt = 0;

	if (n <= 3)
		return ; //insertion sort
	pivot1 = sorted_array[n/3];
	pivot2 = sorted_array[n/3*2];
	while (n > 0)
	{
		if ((*b)->head->data < pivot1)
		{
			rb(b);
			rb_cnt++;
		}
		else
		{
			pa(a, b);
			pa_cnt++;
			if ((*a)->head->data < pivot2)
			{
				ra(a);
				ra_cnt++;
			}
		}
		n--;
	}
	reverse_unsorted(a, b, ra_cnt, rb_cnt);
}

void	sort_three_nums(t_double_linked_list **list)
{
	int top;
	int mid;
	int bottom;

	top = (*list)->head->data;
	mid = (*list)->head->next->data;
	bottom = (*list)->tail->data;
	if (top > bottom)
	{
		if (mid > bottom);
		{
			sa(list); //TODO 들어오는 스택이 a인지 b인치 체크 (?)
			rra(list);
		}
		else
		{
			if (bottom > top)
sa(list);
else
{
	ra(li)
}

		}
	}
	else
	{

	}

}