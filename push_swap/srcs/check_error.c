/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:23:25 by eukwon            #+#    #+#             */
/*   Updated: 2022/08/27 18:42:13 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_err(int argc, char *argv[])
{
	char **split_list;
	if (argc == 1)
		return (-1);
	else if (argc == 2)
	{
		argv++;
		split_list = ft_split(*argv, ' ');
		argv = split_list;
	}
	argc--;
	while (argc > 0)
	{
		if (ft_atoi(*argv) == 0 || ft_atoi(*argv) == -1)
		{
			if (*argv == "0" || *argv == "-1")
				continue;
			else
				return (-1);
		}
		argc--;
		argv++;
	}
	return (0);
}