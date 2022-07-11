/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/11 13:44:43 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// void	push_swap(int *num_list)
// {

// }

// void	quick_sort(int *num_arr, int L, int R)
// {
// 	int	left;
// 	int	right;
// 	int pivot;

// 	left = L;
// 	right = R;
// 	pivot = num_arr[(L + R) / 2];
// 	while (num_arr[left] < pivot)
// 		left++;
// 	while (num_arr[right] > pivot)
// 		right--;
// 	if (left <= right)
// }

void	swap(int *num_arr, int idx1, int idx2)
{
	int	tmp;

	tmp = num_arr[idx1];
	num_arr[idx1] = num_arr[idx2];
	num_arr[idx2] = tmp;
}

void quick_sort(int *num_arr, int L, int R){
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
	}
	if (L < right)
		quick_sort(num_arr, L, right);
	if (left < R)
		quick_sort(num_arr, left, R);
}

int	main(int argc, char *argv[])
{
	int	num_arr[] = {3, 4, 1, 5, 8, 9, 2};
	quick_sort(num_arr, 0, 6);
	for (int i = 0; i <= 6; i++)
	{
		printf("%d ", num_arr[i]);
	}
}
