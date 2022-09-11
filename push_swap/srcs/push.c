/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:37:45 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/11 15:43:59 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_double_linked_list **a, t_double_linked_list **b)
{
	push(a, pop(b));
	ft_printf("pa\n");
}

void	pb(t_double_linked_list **a, t_double_linked_list **b)
{
	push(b, pop(a));
	ft_printf("pb\n");
}