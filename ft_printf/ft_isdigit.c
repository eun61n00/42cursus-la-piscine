/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:36:08 by eukwon            #+#    #+#             */
/*   Updated: 2022/06/17 11:36:11 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}