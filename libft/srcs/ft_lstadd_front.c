/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:07:16 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/14 10:40:43 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new->next = *lst;
	else
		new->next = NULL;
	*lst = new;
}
