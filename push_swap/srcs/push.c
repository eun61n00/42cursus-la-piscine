/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:37:45 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/03 18:23:20 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_num_stack *a, t_num_stack *b)
{
	t_num_stack	*tmp;

	if (b->data == NULL)
		return ;
	tmp = a->next;
	a->next = b;
	b = b->next;
	a->next->next = tmp;
}

void	pb(t_num_stack *a, t_num_stack *b)
{
	t_num_stack *tmp;

	if (a->data == NULL)
		return;
	if (b == NULL)
		b = new_stack(a->data);
	tmp = b->next;
	b->next = a;
	a = a->next;
	b->next->next = tmp;
}