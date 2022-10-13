/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:41:05 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/27 15:44:22 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	check_argv(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (argv[2][1])
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (1);
}

int	valid_division(char op, int div)
{
	if (op == '/' && div == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (op == '%' && div == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	n1;
	int	n2;

	if (!check_argv(argc, argv))
		return (0);
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	if (!(valid_division(argv[2][0], n2)))
		return (0);
	if (argv[2][0] == '+')
		ft_putnbr(n1 + n2);
	else if (argv[2][0] == '-')
		ft_putnbr(n1 - n2);
	else if (argv[2][0] == '*')
		ft_putnbr(n1 * n2);
	else if (argv[2][0] == '/')
		ft_putnbr(n1 / n2);
	else if (argv[2][0] == '%')
		ft_putnbr(n1 % n2);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
