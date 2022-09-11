/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:37:39 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/11 15:56:56 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_double_linked_list **a)
{
	t_double_linked_list_node *tmp;
	t_double_linked_list_node *tmp2;

	tmp = pop(a);
	tmp2 = pop(a);
	if (!tmp || !tmp2)
		return ;
	add_double_linked_list(a, tmp);
	add_double_linked_list(a, tmp2);
	ft_printf("sa\n");
}

void	sb(t_double_linked_list **b)
{
	t_double_linked_list_node *tmp;
	t_double_linked_list_node *tmp2;

	tmp = pop(b);
	tmp2 = pop(b);
	if (!tmp || !tmp2)
		return ;
	add_double_linked_list(b, tmp);
	add_double_linked_list(b, tmp2);
	ft_printf("sb\n");
}