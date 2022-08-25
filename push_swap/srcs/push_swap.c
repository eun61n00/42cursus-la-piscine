/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:53:47 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/16 14:21:10 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *num_arr, int idx1, int idx2)
{
	int	tmp;

	tmp = num_arr[idx1];
	num_arr[idx1] = num_arr[idx2];
	num_arr[idx2] = tmp;
}

void	quick_sort(int *num_arr, int L, int R)
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
	}
	if (L < right)
		quick_sort(num_arr, L, right);
	if (left < R)
		quick_sort(num_arr, left, R);
}