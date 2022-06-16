/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:34:06 by eukwon            #+#    #+#             */
/*   Updated: 2022/06/16 16:36:46 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
void	parse(const char *string, va_list ap);
void	check_type(char c, va_list ap);
void	print_char(va_list ap);
void	print_str(va_list ap);
void	print_ptr(va_list ap);

void	write_nbr(int n);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);


#endif