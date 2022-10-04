/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:00:34 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/05 06:16:11 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*seperate_b_to_a(int n, t_double_linked_list **a, \
						t_double_linked_list **b, int *sorted_array)
{
	int	*variables_array;

	variables_array = init_variables(n);
	while (n-- > 0)
	{
		if ((*b)->head->data < sorted_array[variables_array[3]])
		{
			rb(b);
			variables_array[1]++;
		}
		else
		{
			pa(a, b);
			variables_array[2]++;
			if ((*a)->head->data < sorted_array[variables_array[4]])
			{
				ra(a);
				variables_array[0]++;
			}
		}
	}
	return (variables_array);
}

static int	check_nums_in_b(int n, \
							t_double_linked_list **a, \
							t_double_linked_list **b)
{
	int	n_cp;

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
		return (1);
	}
	if (already_sorted_reverse(b, n) == 1)
	{
		while (n > 0)
		{
			pa(a, b);
			n--;
		}
		return (1);
	}
	return (0);
}

void	b_to_a(int n, t_double_linked_list **a, \
				t_double_linked_list **b, \
				int *sorted_array)
{
	int	*op_cnt;

	(*b)->excuted = 1;
	if (check_nums_in_b(n, a, b) == 1)
		return ;
	op_cnt = seperate_b_to_a(n, a, b, sorted_array);
	a_to_b(op_cnt[2] - op_cnt[0], a, b, &sorted_array[n / 3 * 2]);
	reverse_unsorted(a, b, op_cnt[0], op_cnt[1]);
	a_to_b(op_cnt[0], a, b, &sorted_array[n / 3]);
	b_to_a(op_cnt[1], a, b, sorted_array);
	free(op_cnt);
}
