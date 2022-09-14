// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   quick_sort.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/09/12 09:50:28 by eukwon            #+#    #+#             */
// /*   Updated: 2022/09/14 08:42:32 by eukwon           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/push_swap.h"

// void	A_to_B(int r, t_double_linked_list **a, t_double_linked_list **b)
// {
// 	int	pivot;
// 	int	ra_cnt, pb_cnt;

// 	pivot = (*a)->head->data;
// 	while (r > 0)
// 	{
// 		if ((*a)->head->data > pivot)
// 		{
// 			ra(a);
// 		}
// 		else
// 		{
// 			pb(a, b);
// 		}
// 	}
// }

// void 	B_to_A(int r, t_double_linked_list **a, t_double_linked_list **b)
// {
// 	int	p1, p2;
// 	int	ra_cnt, rb_cnt, pa_cnt, pb_cnt;

// 	pivot = 0;
// 	while (r-- > 0) {
// 		if ((*a)->head->data <)
// 	}
// }

// void	sort(t_double_linked_list **a, t_double_linked_list **b)
// {
// 	int ra_cnt, pb_cnt;
// 	while ((*b)->size <= 0)
// 	{
// 		A_to_B();
// 		B_to_A();
// 	}

// void	quick_sort(int *num_arr, int L, int R)
// {
// 	int left = L, right = R;
// 	int pivot = num_arr[(L + R) / 2];

// 	while (left <= right)
// 	{
// 		while (num_arr[left] < pivot)
// 			left++;
// 		while (num_arr[right] > pivot)
// 			right--;
// 		if (left <= right)
// 		{
// 			swap(num_arr, left, right);
// 			left++;
// 			right--;
// 		}
// 		if (L < right) //아직 끝까지 정렬하지 못함
// 			quick_sort(num_arr, L, right);
// 		if (left < R)
// 			quick_sort(num_arr, left, R);
// 	}
// }