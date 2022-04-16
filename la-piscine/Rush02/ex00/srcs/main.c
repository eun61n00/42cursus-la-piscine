/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:49:22 by junsoh            #+#    #+#             */
/*   Updated: 2022/01/23 20:30:58 by junsoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom.h"

int	main(int argc, char *argv[])
{
	t_bucket		*dict;
	t_node			*ret;
	int				i;
	char			**parsed_str;

	i = 0;
	parsed_str = parse_file(parsed_str, INIT_DICT);
	dict = make_dict(parsed_str);
	if (argc > 3 || argc < 2)
	{
		print_err(-1);
		return (1);
	}
	if (argc == 2)
	{
		ret = find_param(dict, ft_atoi(argv[1]));
	}
	return (0);
}