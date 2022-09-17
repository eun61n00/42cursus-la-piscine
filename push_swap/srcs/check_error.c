/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:23:25 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/17 17:22:36 by eukwon           ###   ########.fr       */
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

	return (0);
}