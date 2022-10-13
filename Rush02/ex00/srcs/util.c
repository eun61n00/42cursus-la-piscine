/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:16:50 by junsoh            #+#    #+#             */
/*   Updated: 2022/01/23 20:09:06 by junsoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom.h"

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_str_sep_len(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] != sep && str[i])
		i++;
	return (i);
}

char	*ft_trim(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] != ' ')
		{
			dest[j] = src[i];
			j++;
		}
		i++;
	}
	return (dest);
}

int	count_word(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == sep)
		{
			i++;
			continue ;
		}
		count++;
		while (str[i] != sep && str[i])
			i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

unsigned int	ft_atoi(char *str)
{
	unsigned	sign;
	unsigned	ret;
	int			i;

	i = 0;
	sign = 1;
	ret = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	if (sign < 0)
		return (-1);
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		if (ret < 0)
			return (-1);
		i++;
	}
	return (ret);
}
