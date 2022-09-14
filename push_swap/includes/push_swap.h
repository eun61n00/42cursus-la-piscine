/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:39:19 by eukwon            #+#    #+#             */
/*   Updated: 2022/09/14 13:48:36 by eukwon           ###   ########.fr       */
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
void	rb(t_double_linked_list **a);
void	rra(t_double_linked_list **a);
void	rrb(t_double_linked_list **b);
void	rrr(t_double_linked_list **a, t_double_linked_list **b);


t_double_linked_list_node	*new_double_linked_list_node(int data);
void	append_double_linked_list(t_double_linked_list **list, t_double_linked_list_node *new_node);
void	add_double_linked_list(t_double_linked_list **list, t_double_linked_list_node *new_node);
t_double_linked_list_node *pop(t_double_linked_list **list, int node_idx);
void	push(t_double_linked_list **list, t_double_linked_list_node *node);

int	*make_sorted_array(t_double_linked_list **a);
int	*copy_data(t_double_linked_list **a);

void	a_to_b(int n, t_double_linked_list **a, t_double_linked_list **b, int *sorted_array);
void	b_to_a(int n, t_double_linked_list **a, t_double_linked_list **b, int *sorted_array);

#endif
