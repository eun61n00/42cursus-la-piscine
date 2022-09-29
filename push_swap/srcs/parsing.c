/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:27:15 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/29 18:48:28 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	contain_alpha(char *argv)
{
	while (*argv)
	{
		if (ft_isalpha(*argv))
			return (1);
		argv++;
	}
	return (0);
}

static int	is_valid(char *argv)
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
	t_double_linked_list	*a;

	argv++;
	a = new_double_linked_list();
	if (a == NULL)
		return (NULL);
	if (argc == 2)
		argv = ft_split(*argv, ' ');
	while (*argv)
	{
		if (is_valid(*argv) == 0)
			return (NULL);
		append_double_linked_list(&a, \
			new_double_linked_list_node(ft_atoi(*argv++)));
	}
	return (a);
}
