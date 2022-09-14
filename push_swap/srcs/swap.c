/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:37:39 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/14 13:46:35 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_double_linked_list **a)
{
	t_double_linked_list_node *tmp;
	t_double_linked_list_node *tmp2;

	tmp = pop(a, 0);
	tmp2 = pop(a, 0);
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

	tmp = pop(b, 0);
	tmp2 = pop(b, 0);
	if (!tmp || !tmp2)
		return ;
	add_double_linked_list(b, tmp);
	add_double_linked_list(b, tmp2);
	ft_printf("sb\n");
}

void ss(t_double_linked_list **a, t_double_linked_list **b)
{
	t_double_linked_list_node *tmp;
	t_double_linked_list_node *tmp2;

	tmp = pop(a, 0);
	tmp2 = pop(a, 0);
	if (!tmp || !tmp2)
		return ;
	add_double_linked_list(a, tmp);
	add_double_linked_list(a, tmp2);
	tmp = pop(b, 0);
	tmp2 = pop(b, 0);
	if (!tmp || !tmp2)
		return ;
	add_double_linked_list(b, tmp);
	add_double_linked_list(b, tmp2);
	ft_printf("ss\n");
}