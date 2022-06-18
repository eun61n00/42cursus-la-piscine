/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:32:25 by eukwon            #+#    #+#             */
/*   Updated: 2022/06/18 16:58:53 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_type(int *ret, char c, va_list *ap)
{
	int	value;
	char *chr_ptr;

	if (c == 'c')
		*ret += ft_putchar(va_arg(*ap, int));
	else if (c == 's')
		*ret += ft_putstr(va_arg(*ap, char *));
	else if (c == 'p')
	{
		*ret += ft_putstr("0x");
		*ret += ft_putaddr((va_arg(*ap, void *)), "0123456789abcdef");
	}
	else if (c == 'd')
		*ret += ft_putnbr_base(va_arg(*ap, int), "0123456789");
	else if (c == 'i')
	{
		value = va_arg(*ap, int);
		chr_ptr = ft_itoa(value);
		ft_putstr(chr_ptr);
		free(chr_ptr);
		*ret += get_digit(value);
	}
	else if (c == 'u')
		*ret += ft_putnbr_base_unsigned(va_arg(*ap, int), "0123456789");
	else if (c == 'X')
		*ret += ft_putnbr_base_unsigned(va_arg(*ap, int), "0123456789ABCDEF");
	else if (c == 'x')
		*ret += ft_putnbr_base_unsigned(va_arg(*ap, int), "0123456789abcdef");
	else if (c == '%')
		*ret += ft_putchar('%');
	else
		return ;
}

static void	parse(int *ret, const char *string, va_list *ap)
{
	while (*string)
	{
		if (*string != '%')
		{
			ft_putchar(*string);
			*ret += 1;
		}
		else
		{
			string++;
			check_type(ret, *string, ap);
		}
		string++;
	}
}

int	ft_printf(const char *string, ...)
{
	va_list ap;
	int		ret;

	ret = 0;
	va_start(ap, string);
	parse(&ret, string, &ap);
	va_end(ap);

	return ret;
}

// int main(void)
// {
// 	long long a = LONG_MIN;
// 	long long b = LONG_MAX;
// 	printf("return: %d\n", ft_printf("%p %p\n", &a, &b));
// 	printf("return: %d\n", printf("%p %p\n", &a, &b));
// }
