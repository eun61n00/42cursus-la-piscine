/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:37:45 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/14 13:47:20 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_double_linked_list **a, t_double_linked_list **b)
{
	push(a, pop(b, 0));
	ft_printf("pa\n");
}

void	pb(t_double_linked_list **a, t_double_linked_list **b)
{
	push(b, pop(a, 0));
	ft_printf("pb\n");
}