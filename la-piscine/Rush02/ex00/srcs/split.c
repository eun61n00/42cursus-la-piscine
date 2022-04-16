/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:23:14 by junsoh            #+#    #+#             */
/*   Updated: 2022/01/23 20:29:53 by junsoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom.h"

char	*get_str(char *origin_str, int len)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str = ft_strncpy(str, origin_str, len);
	return (str);
}

char	**ft_split(char **dest, char *str, char sep)
{
	int		arr_size;
	int		i;
	int		j;

	arr_size = count_word(str, sep);
	dest = (char **) malloc(sizeof(char *) * (arr_size + 1));
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	while (i < arr_size)
	{
		if (str[j] == sep)
		{
			j++;
			continue ;
		}
		dest[i] = get_str(&str[j], ft_str_sep_len(&str[j], sep));
		if (!dest[j])
			return (0);
		j += ft_str_sep_len(&str[j], sep);
		i++;
	}
	dest[i] = 0;
	return (dest);
}
