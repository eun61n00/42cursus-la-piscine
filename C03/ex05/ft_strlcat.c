/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:41:28 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/13 20:17:05 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_len(char *arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	return_num;

	dest_len = get_len(dest);
	src_len = get_len(src);
	j = 0;
	return_num = 0;
	while (dest[return_num] && return_num < size)
		return_num++;
	if (size > 0)
	{
		while ((dest_len < size - 1) && src[j])
		{
			dest[dest_len] = src[j];
			j++;
			dest_len++;
		}
	}
	dest[dest_len] = '\0';
	return (src_len + return_num);
}
