/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:39:19 by eukwon            #+#    #+#             */
/*   Updated: 2022/08/27 16:54:06 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../lib/libft/includes/libft.h"
#include "../lib/ft_printf/includes/ft_printf.h"

typedef struct s_num_stack {
	int *num;
	struct s_stack *prev;
	struct s_stack *next;
}	t_num_stack;

typedef struct s_cmd_stack {
	char *cmd;
	struct s_cmd_stack *prev;
	struct s_cmd_stack *next;
}	t_cmd_stack;

int check_err(int argc, char *argv[]);
char ** parsing(int argc, char *argv[]);

#endif
