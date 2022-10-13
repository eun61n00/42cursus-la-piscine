/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:31:53 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/24 17:05:02 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*dest;
	int		i;

	src_len = ft_strlen(src);
	dest = malloc(src_len + 1);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*temp;

	temp = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	if (temp == NULL)
		return (NULL);
	while (i < ac)
	{
		temp[i].size = ft_strlen(av[i]);
		temp[i].str = av[i];
		temp[i].copy = ft_strdup(av[i]);
		i++;
	}
	temp[i].str = 0;
	return (temp);
}
