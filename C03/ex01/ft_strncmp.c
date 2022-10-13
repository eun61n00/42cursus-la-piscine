/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:17:59 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/17 13:25:11 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	s1_unsigned;
	unsigned char	s2_unsigned;
	unsigned int	i;

	i = 0;
	while (i < n && s1[i])
	{
		s1_unsigned = s1[i];
		s2_unsigned = s2[i];
		if (s1_unsigned > s2_unsigned)
			return (1);
		else if (s1_unsigned < s2_unsigned)
			return (-1);
		else
			i++;
	}
	if (i < n)
	{
		if (s2[i])
			return (-1);
		else
			return (0);
	}
	return (0);
}
