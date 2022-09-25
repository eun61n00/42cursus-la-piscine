/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:27:15 by eukwon            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/17 16:29:26 by eukwon           ###   ########.fr       */
=======
/*   Updated: 2022/09/20 14:38:40 by eukwon           ###   ########.fr       */
>>>>>>> d136cd08d8bb3388886096d04115816aa7b4c775
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_double_linked_list	*parsing(int argc, char *argv[])
{
	t_double_linked_list *a;

	argv++;
	a = (t_double_linked_list *)malloc(sizeof(t_double_linked_list));
	if (a == NULL)
		return NULL;
	a->head = NULL;
	a->size = 0;
	a->tail = NULL;
	if (argc == 2)
		argv = ft_split(*argv, ' ');
	while (*argv)
		append_double_linked_list(&a, new_double_linked_list_node(ft_atoi(*argv++)));
	return (a);
}

//TODO 문자가 들어왔을 때 에러 처리
//TODO 중복 검사