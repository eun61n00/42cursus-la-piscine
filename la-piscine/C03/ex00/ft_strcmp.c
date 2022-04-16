/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:46:44 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/13 17:34:57 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	s1_unsigned;
	unsigned char	s2_unsigned;

	i = 0;
	while (s1[i] != '\0')
	{
		s1_unsigned = s1[i];
		s2_unsigned = s2[i];
		if (s1_unsigned > s2_unsigned)
			return (1);
		else if (s1_unsigned < s2_unsigned)
			return (-1);
		else
		{
			i++;
			continue ;
		}
	}
	if (s2[i] != '\0')
		return (-1);
	else
		return (0);
}
