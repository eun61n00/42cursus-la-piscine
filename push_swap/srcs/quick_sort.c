/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:50:28 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/17 16:16:33 by eukwon           ###   ########.fr       */
=======
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:50:28 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/19 22:12:37 by eukwon           ###   ########.fr       */
>>>>>>> d136cd08d8bb3388886096d04115816aa7b4c775
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_unsorted(t_double_linked_list **a, t_double_linked_list **b, int ra_cnt, int rb_cnt)
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
<<<<<<< HEAD
		sort_few_nums(n, a);
=======
		sort_few_nums(a);
		while (n > 0)
		{
			pb(a, b);
			n--;
		}
>>>>>>> d136cd08d8bb3388886096d04115816aa7b4c775
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
<<<<<<< HEAD
	int ra_cnt = 0, pa_cnt = 0, rb_cnt = 0, i = n;

	if (n <= 3)
	{
		while (i > 0)
		{
			pa(a, b);
			i--;
		}
		sort_few_nums(n, a);
=======
	int ra_cnt = 0, pa_cnt = 0, rb_cnt = 0;

	if (n <= 3)
	{
		sort_few_nums(b);
		while (n > 0)
		{
			pa(a, b);
			n--;
		}
>>>>>>> d136cd08d8bb3388886096d04115816aa7b4c775
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
	a_to_b(pa_cnt - ra_cnt, a, b, sorted_array);
	reverse_unsorted(a, b, ra_cnt, rb_cnt);
<<<<<<< HEAD
=======
	a_to_b(pa_cnt - ra_cnt, a, b, sorted_array);
>>>>>>> d136cd08d8bb3388886096d04115816aa7b4c775
	a_to_b(rb_cnt, a, b, sorted_array);
	b_to_a(ra_cnt, a, b, sorted_array);
}

<<<<<<< HEAD
void	sort_few_nums(int n, t_double_linked_list **list)
=======
void	sort_few_nums(t_double_linked_list **list)
>>>>>>> d136cd08d8bb3388886096d04115816aa7b4c775
{
	int top;
	int mid;
	int bottom;

	top = (*list)->head->data;
<<<<<<< HEAD
	if (n == 1)
		return ;
	else if (n == 2)
	{
		bottom = (*list)->head->next->data;
		if (top > bottom)
			sa(list);
		return ;
	}
	mid = (*list)->head->next->data;
	bottom = (*list)->head->next->next->data;
	if ((top < mid) && mid < bottom)
		return ;
	if ((top > mid && top < bottom)
		|| (top > mid && mid > bottom)
		|| (top < bottom && bottom < mid))
	{
		sa(list);
		sort_few_nums(n, list);
	}
=======
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
>>>>>>> d136cd08d8bb3388886096d04115816aa7b4c775
	else if (top > bottom && mid < bottom)
		ra(list);
	else
		rra(list);
<<<<<<< HEAD
}

// void	sort_few_nums_desc(int n, t_double_linked_list **list)
// {
// 	int top;
// 	int mid;
// 	int bottom;

// 	top = (*list)->head->data;
// 	if (n == 1)
// 		return ;
// 	else if (n == 2)
// 	{
// 		bottom = (*list)->head->next->data;
// 		if (top < bottom)
// 			sa(list);
// 		return ;
// 	}
// 	mid = (*list)->head->next->data;
// 	bottom = (*list)->head->next->next->data;
// 	if ((top > mid) && mid > bottom)
// 		return ;
// 	if ((top < mid) && (top > bottom) // 2 3 1
// 		|| (top > mid) && (mid < bottom)) //
// 	{
// 		sb(list);
// 		sort_few_num(list);
// 	}

// 	if ((top > mid && top < bottom) //2 1 3 ->rra
// 		|| (top > mid && mid > bottom)
// 		|| (top < bottom && bottom < mid)) // 1 3 2 -> rb
// 	{
// 		rb(list);
// 		sort_few_nums(n, list);
// 	}
// 	else if (top > bottom && mid < bottom) // 3 1 2
// 		ra(list);
// 	else
// 		rra(list);
// }
=======
}
>>>>>>> d136cd08d8bb3388886096d04115816aa7b4c775
