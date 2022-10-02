/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:27:15 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/02 21:53:37 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	contain_only_digit(char *argv)
{
	while (*argv)
	{
		if (!ft_isdigit(*argv))
			return (0);
		argv++;
	}
	return (1);
}

static int	is_valid(char *argv)
{
	if (ft_strlen(argv) > 11)
		return (0);
	if (ft_strchr(argv, '-') != NULL && ft_atoi(argv) >= 0)
		return (0);
	else if (ft_strchr(argv, '-') == NULL && ft_atoi(argv) < 0)
		return (0);
	else if (contain_only_digit(argv) == 0)
		return (0);
	else
		return (1);
}

t_double_linked_list	*parsing(int argc, char *argv[])
{
	t_double_linked_list	*a;
	char					**split_array;

	argv++;
	a = new_double_linked_list();

	if (a == NULL)
		return (NULL);
	(void)argc;
	while (*argv)
	{
		if (ft_strchr(*argv, ' '))
		{
			split_array = ft_split(*argv, ' ');
			while (*split_array)
			{
				if (is_valid(*split_array) == 0)
					return (NULL);
				append_double_linked_list(&a, new_double_linked_list_node(ft_atoi(*split_array++)));
			}
			free(split_array);
			argv++;
		}
		else
		{
			if (is_valid(*argv) == 0)
				return (NULL);
			append_double_linked_list(&a, \
				new_double_linked_list_node(ft_atoi(*argv++)));
		}
	}
	return (a);
}
