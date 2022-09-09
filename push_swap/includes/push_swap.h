/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:39:19 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/09 11:06:59 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../lib/libft/includes/libft.h"
#include "../lib/ft_printf/includes/ft_printf.h"

typedef struct s_num_stack {
	int data;
	struct s_num_stack *next;
}	t_num_stack;

typedef struct s_cmd_stack {
	char *cmd;
	struct s_cmd_stack *prev;
	struct s_cmd_stack *next;
}	t_cmd_stack;

int 	check_err(int argc, char *argv[]);
t_num_stack	*parsing(char *argv[]);
void	sa(t_num_stack **a);
void	pa(t_num_stack **a, t_num_stack **b);
void	pb(t_num_stack **a, t_num_stack **b);

void	ra(t_num_stack **a);
void	rra(t_num_stack **a);

t_num_stack	*new_stack(int data);
t_num_stack	*get_tail(t_num_stack *stack);
void		add_tail(t_num_stack **stack, t_num_stack *new_stack);

#endif
