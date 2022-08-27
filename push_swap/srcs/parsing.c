/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:27:15 by eukwon            #+#    #+#             */
/*   Updated: 2022/08/27 18:19:25 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char ** parsing(int argc, char *argv[])
{
	char **split_list;
	t_num_stack stack;

	argc--;
	while (argc > 0)
	{
		split_list = ft_split(*argv);
	}
	char **linked_list;

	linked_list = ft_split(argc, ' ');

	return (linked_list);
}