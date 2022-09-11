/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:39:19 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/11 16:39:06 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../lib/libft/includes/libft.h"
#include "../lib/ft_printf/includes/ft_printf.h"

typedef struct s_double_linked_list_node {
	struct s_double_linked_list_node *prev;
	int data;
	struct s_double_linked_list_node *next;
}	t_double_linked_list_node;

typedef struct s_double_linked_list {
	struct s_double_linked_list_node *head;
	struct s_double_linked_list_node *tail;
	int	size;
} t_double_linked_list;

int 	check_err(int argc, char *argv[]);
t_double_linked_list	*parsing(char *argv[]);
void	sa(t_double_linked_list **a);
void	sb(t_double_linked_list **b);

void	pa(t_double_linked_list **a, t_double_linked_list **b);
void	pb(t_double_linked_list **a, t_double_linked_list **b);

void	ra(t_double_linked_list **a);
void	rra(t_double_linked_list **a);

t_double_linked_list_node	*new_double_linked_list_node(int data);
void	append_double_linked_list(t_double_linked_list **list, t_double_linked_list_node *new_node);
void	add_double_linked_list(t_double_linked_list **list, t_double_linked_list_node *new_node);
t_double_linked_list_node *pop(t_double_linked_list **list);
void	push(t_double_linked_list **list, t_double_linked_list_node *node);

void	indexing(t_double_linked_list **a);

#endif
