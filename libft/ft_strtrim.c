/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunbin <eunbin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:14:30 by eukwon            #+#    #+#             */
/*   Updated: 2022/03/15 13:57:22 by eunbin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;

	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1) - 1;
	while (start < end && ft_strchr(set, *start))
		start++;
	while (end >= start && ft_strchr(set, *end))
		end--;
	return (ft_substr(s1, start - s1, end - start + 1));
}
