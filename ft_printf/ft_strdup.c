/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:35:45 by eukwon            #+#    #+#             */
/*   Updated: 2022/06/17 11:35:52 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_len;
	size_t	i;
	char	*dupstr;

	str_len = ft_strlen(s1);
	dupstr = (char *)malloc(sizeof(char) * (str_len + 1));
	if (dupstr == NULL)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		dupstr[i] = s1[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}
