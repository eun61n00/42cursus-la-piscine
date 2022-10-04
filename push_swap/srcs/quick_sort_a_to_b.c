/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:50:28 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/05 06:28:53 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*seperate_a_to_b(int n, t_double_linked_list **a, \
								t_double_linked_list **b, int *sorted_array)
{
	int	*variables_array;

	variables_array = init_variables(n);
	while (n-- > 0)
	{
		if ((*a)->head->data >= sorted_array[variables_array[4]])
		{
			ra(a);
			variables_array[0]++;
		}
		else
		{
			pb(a, b);
			variables_array[2]++;
			if ((*b)->head->data >= sorted_array[variables_array[3]])
			{
				rb(b);
				variables_array[1]++;
			}
		}
	}
	return (variables_array);
}

void	a_to_b(int n, t_double_linked_list **a, \
						t_double_linked_list **b, \
						int *sorted_array)
{
	int	*op_cnt;

	if (n <= 3)
	{
		sort_few_nums(a, b, n);
		return ;
	}
	if (already_sorted(a, n) == 1)
		return ;
	op_cnt = seperate_a_to_b(n, a, b, sorted_array);
	reverse_unsorted(a, b, op_cnt[0], op_cnt[1]);
	a_to_b(op_cnt[0], a, b, &sorted_array[n / 3 * 2]);
	b_to_a(op_cnt[1], a, b, &sorted_array[n / 3]);
	b_to_a(op_cnt[2] - op_cnt[1], a, b, sorted_array);
	free(op_cnt);
}
