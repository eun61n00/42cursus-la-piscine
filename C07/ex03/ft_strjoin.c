/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:30:17 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/26 00:39:04 by eukwon           ###   ########.fr       */
/*   Updated: 2022/01/26 20:14:50 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	return (dest);
}

char	*join(int size, char **strs, char *sep, int arr_len)
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(sizeof(char) * arr_len);
	if (arr == 0)
		return (0);
	arr[0] = 0;
	while (strs[i])
	{
		arr = ft_strcat(arr, strs[i]);
		if (i < size - 1)
			arr = ft_strcat(arr, sep);
		i++;
	}
	return (arr);
}

char	*freeable_empty_string(void)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char));
	arr[0] = 0;
	return (arr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		arr_len;
	int		i;

	i = 0;
	arr_len = 0;
	if (size < 1)
		return (freeable_empty_string());
	if (size == 1)
	{
		arr = join(size, strs, sep, ft_strlen(strs[0]));
		return (arr);
	}
	while (strs[i])
	{
		arr_len += ft_strlen(strs[i]);
		i++;
	}
	arr_len += ft_strlen(sep) * (size - 1) + 1;
	arr = join(size, strs, sep, arr_len);
	arr[arr_len - 1] = '\0';
	return (arr);
}

int	main(void)
{
	char **strs;

	strs = (char **)malloc(sizeof(char) * 3);
	strs[0] = "hello";
	strs[1] = "goodbye";
	strs[2] = "test##";
	char sep[6] = "*-*-*";

	printf("%s\n", ft_strjoin(3, strs, sep));
}
