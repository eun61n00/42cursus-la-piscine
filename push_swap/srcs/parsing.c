/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:27:15 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/17 16:29:26 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_double_linked_list	*parsing(char *argv[])
{
	t_double_linked_list *a;

	argv++;
	a = (t_double_linked_list *)malloc(sizeof(t_double_linked_list));
	if (a == NULL)
		return NULL;
	a->head = NULL;
	a->size = 0;
	a->tail = NULL;
	while (*argv)
		append_double_linked_list(&a, new_double_linked_list_node(ft_atoi(*argv++)));
	return (a);
}