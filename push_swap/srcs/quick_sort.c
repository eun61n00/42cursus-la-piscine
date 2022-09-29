/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:50:28 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/29 18:59:47 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int	pivot1_idx;
	int	pivot2_idx;
	int	ra_cnt;
	int	rb_cnt;
	int	pb_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;

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
	int pivot1_idx;
	int	pivot2_idx;
	int ra_cnt;
	int	pa_cnt;
	int	rb_cnt;
	int n_cp;

	ra_cnt = 0;
	pa_cnt = 0;
	rb_cnt = 0;
	n_cp = n;

	*i = 1;
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
