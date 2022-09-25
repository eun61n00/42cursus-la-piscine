/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:23:25 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/25 13:13:24 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int check_err(int argc, char *argv[])
// {
// 	if (argc == 1)
// 		return (-1);
// 	return (0);
// }

int contain_duplicates(t_double_linked_list **a)
{
	t_double_linked_list_node	*tmp;
	t_double_linked_list_node	*tmp2;

	tmp = (*a)->head;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}