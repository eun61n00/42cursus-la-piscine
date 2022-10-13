/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:26:09 by eukwon            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/19 15:26:56 by eukwon           ###   ########.fr       */
=======
/*   Updated: 2022/01/19 23:41:15 by eukwon           ###   ########.fr       */
>>>>>>> 3b9cf95a9aa82eaf7d1fbdf9fe52000dc595cc77
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int		i;
	unsigned char	c;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i])
	{
		c = str[i];
		if (c <= 31 || c >= 127)
			return (0);
		i++;
	}
	return (1);
}
