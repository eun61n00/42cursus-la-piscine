/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:04:43 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/27 13:48:26 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>
int		is_whitespace(char c);
int		is_numeric(char c);
int		ft_atoi(char *str);
void	ft_putnbr(int nbr);
int		check_argv(int argc, char **argv);
int		valid_division(char op, int div);

#endif
