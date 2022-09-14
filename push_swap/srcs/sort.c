/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:35:55 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/14 08:47:42 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *num_arr, int L, int R);
void	quick_sort(int *num_arr, int L, int R);

//미리 정렬 후, 인덱싱
int	*copy_data(t_double_linked_list **a)
{
	int	*num_arr;
	int	i;
	t_double_linked_list_node *a_node;

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

void	swap(int *num_arr, int L, int R)
{
	int	tmp;

	tmp = num_arr[L];
	num_arr[L] = num_arr[R];
	num_arr[R] = tmp;
}

void	quick_sort(int *num_arr, int L, int R)
{
	int left = L, right = R;
	int pivot = num_arr[(L + R) / 2];

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
		if (L < right) //아직 끝까지 정렬하지 못함
			quick_sort(num_arr, L, right);
		if (left < R)
			quick_sort(num_arr, left, R);
	}
}

int	*sort(t_double_linked_list **a)
{
	int	*sorted_arr;

	sorted_arr = copy_data(a);
	quick_sort(sorted_arr, 0, (*a)->size - 1);
	return (sorted_arr);
}