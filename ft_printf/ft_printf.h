/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:34:06 by eukwon            #+#    #+#             */
/*   Updated: 2022/06/18 17:07:59 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int					ft_printf(const char *string, ...);
void				write_nbr(const int n);
int					ft_putchar(const char c);
size_t				ft_strlen(const char *str);
int					ft_putstr(const char *str);
char				*ft_strdup(const char *s1);
int					ft_isdigit(const char c);
int					ft_atoi(const char *str);
int					ft_putnbr_base(const int nbr, const char *base);
int					ft_putnbr_base_unsigned(const int nbr, const char *base);
int					ft_putaddr(const void *ptr_addr, const char *base);
char				*ft_itoa(const int n);
size_t				get_digit(const int n);

#endif