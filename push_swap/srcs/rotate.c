/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:37:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/09 11:10:21 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_num_stack **a)
{
	t_num_stack *tmp;

	tmp = *a;

	*a = (*a)->next;
	tmp->next = NULL;
	get_tail(*a)->next = tmp;
}

void	rra(t_num_stack **a)
{
	t_num_stack *tmp;
	t_num_stack *tmp2;

	tmp = get_tail(*a);
	int i = tmp->data;
	tmp2 = (*a);
	*a = new_stack(i);
	free(*tmp);
	*tmp = NULL;
	(*a)->next = tmp2;
	// tmp = NULL;
}