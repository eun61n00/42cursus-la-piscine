/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:43:09 by eukwon            #+#    #+#             */
/*   Updated: 2022/03/17 15:04:01 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst_ptr > src_ptr)
	{
		while (len)
		{
			dst_ptr[len - 1] = src_ptr[len - 1];
			len--;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
