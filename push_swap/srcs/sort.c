/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:35:55 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/28 13:55:37 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*copy_data(t_double_linked_list **a)
{
	int							*num_arr;
	int							i;
	t_double_linked_list_node	*a_node;

	num_arr = (int *)malloc(sizeof(int) * ((*a)->size));
	a_node = (*a)->head;
	i = 0;
	while (i < (*a)->size)
	{
		num_arr[i] = a_node->data;
		a_node = a_node->next;
		i++;
	}
	return (num_arr);
}

static void	swap(int *num_arr, int L, int R)
{
	int	tmp;

	tmp = num_arr[L];
	num_arr[L] = num_arr[R];
	num_arr[R] = tmp;
}

static void	quick_sort(int *num_arr, int L, int R)
{
	int	left;
	int	right;
	int	pivot;

	left = L;
	right = R;
	pivot = num_arr[(L + R) / 2];
	while (left <= right)
	{
		while (num_arr[left] < pivot)
			left++;
		while (num_arr[right] > pivot)
			right--;
		if (left <= right)
		{
			swap(num_arr, left, right);
			left++;
			right--;
		}
		if (L < right)
			quick_sort(num_arr, L, right);
		if (left < R)
			quick_sort(num_arr, left, R);
	}
}

int	*make_sorted_array(t_double_linked_list **a)
{
	int	*sorted_arr;

	sorted_arr = copy_data(a);
	quick_sort(sorted_arr, 0, (*a)->size - 1);
	return (sorted_arr);
}
