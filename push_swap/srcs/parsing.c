/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:27:15 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/05 09:45:15 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	contain_only_digit(char *argv)
{
	while (*argv)
	{
		if (!ft_isdigit(*argv))
			if (*argv != '+' && *argv != '-')
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

int	split_arguments(char *argv, t_double_linked_list *a)
{
	char	**split_array;
	int		i;

	split_array = ft_split(argv, ' ');
	i = 0;
	if (!split_array[0])
	{
		ft_free_double_pointer(split_array);
		return (0);
	}
	while (split_array[i])
	{
		if (is_valid(split_array[i]) == 0)
			return (0);
		append_double_linked_list(&a, \
			new_double_linked_list_node(ft_atoi(split_array[i])));
		i++;
	}
	ft_free_double_pointer(split_array);
	return (1);
}

static void	create_and_append_double_linked_list_node(\
			t_double_linked_list **a, char *argv)
{
	append_double_linked_list(a, \
		new_double_linked_list_node(ft_atoi(argv)));
}

t_double_linked_list	*parsing(char *argv[])
{
	t_double_linked_list	*a;

	argv++;
	a = new_double_linked_list();
	if (a == NULL)
		return (NULL);
	while (*argv && a)
	{
		if (ft_strchr(*argv, ' '))
		{
			if (split_arguments(*argv, a) == 0)
				return (NULL);
		}
		else
		{
			if (is_valid(*argv) == 0 || !ft_strlen(*argv))
			{
				free_double_linked_list(&a);
				return (NULL);
			}
			create_and_append_double_linked_list_node(&a, *argv);
		}
		argv++;
	}
	return (a);
}
