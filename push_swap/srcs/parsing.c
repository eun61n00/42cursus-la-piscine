/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:27:15 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/25 13:14:07 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int contain_alpha(char *argv)
{
	while (*argv)
	{
		if (ft_isalpha(*argv))
			return (1);
		argv++;
	}
	return (0);
}

int	is_valid(char *argv)
{
	if (ft_strlen(argv) > 11)
		return (0);
	if (ft_strchr(argv, '-') != NULL && ft_atoi(argv) >= 0)
		return (0);
	else if (ft_strchr(argv, '-') == NULL && ft_atoi(argv) < 0)
		return (0);
	else if (contain_alpha(argv) == 1)
		return (0);
	else
		return (1);
}

t_double_linked_list	*parsing(int argc, char *argv[])
{
	t_double_linked_list 	*a;

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
	{
		if (is_valid(*argv) == 0)
			return NULL;
		append_double_linked_list(&a, new_double_linked_list_node(ft_atoi(*argv++)));
	}
	return (a);
}

//TODO 문자가 들어왔을 때 에러 처리
//TODO 중복 검사