/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_unsorted_nums.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 08:59:12 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/02 09:49:46 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_unsorted(t_double_linked_list **a, \
							t_double_linked_list **b, \
							int ra_cnt, int rb_cnt)
{
	if ((*b)->excuted == 1)
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
