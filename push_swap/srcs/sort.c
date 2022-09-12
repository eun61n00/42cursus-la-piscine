/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:35:55 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/12 10:05:54 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *num_arr, int L, int R);
void	quick_sort(int *num_arr, int L, int R);

//미리 정렬 후, 인덱싱하자
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

void	indexing(t_double_linked_list **a)
{
	int	*num_arr = copy_data(a);
	quick_sort(num_arr, 0, (*a)->size);
	t_double_linked_list_node *a_node;
	int	i;
	int	j;

	a_node = (*a)->head;
	i = 0;
	j = 0;
	while (i < (*a)->size)
	{
		j = 0;
		while (j < (*a)->size)
		{
			if (a_node->data == num_arr[j])
			{
				a_node->data = j;
				j++;
				break;
			}
			a_node = a_node->next;
		}
		i++;
	}
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

void	sort()
{

}