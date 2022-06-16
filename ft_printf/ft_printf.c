/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:32:25 by eukwon            #+#    #+#             */
/*   Updated: 2022/06/16 16:56:59 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int	ft_printf(const char *string, ...)
{
	va_list ap;

	va_start(ap, string);
	parse(string, ap);
	va_end(ap);

	return 1;
}

void	parse(const char *string, va_list ap)
{
	char	type;
	while (*string)
	{
		if (*string != '%')
		{
			ft_putchar(*string);
		}
		else
		{
			string++;
			check_type(*string, ap);
		}
		string++;
	}
}

void	check_type(char c, va_list ap)
{
	if (c == 'c')
		print_char(ap);
	else if (c == 's')
		print_str(ap);
	else if (c == 'p')
		print_ptr(ap);
}

void	print_char(va_list ap)
{
	ft_putchar(va_arg(ap, int));
}

void	print_str(va_list ap)
{
	ft_putstr(va_arg(ap, char*));
}

void	print_ptr(va_list ap)
{
	printf("%p", ap);

	va_arg(ap, int);
	//ft_putnbr(addr);
}

int	main(int argc, char **argv)
{
	int i = 1;

	ft_printf("I am %p", i);
}
