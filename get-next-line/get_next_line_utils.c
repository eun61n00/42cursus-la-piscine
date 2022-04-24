/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:26:23 by eukwon            #+#    #+#             */
/*   Updated: 2022/04/23 11:50:53 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len + 1)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
		len--;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len < start)
		return (NULL);
	if (s_len - start < len)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*joinstr;

	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joinstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (joinstr == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		joinstr[i] = *s1++;
		i++;
	}
	while (i < s1_len + s2_len)
	{
		joinstr[i] = *s2++;
		i++;
	}
	joinstr[i] = '\0';
	return (joinstr);
}

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
