/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:07:44 by eukwon            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/19 15:27:33 by eukwon           ###   ########.fr       */
=======
/*   Updated: 2022/01/19 00:33:37 by eukwon           ###   ########.fr       */
/*   Updated: 2022/01/18 21:03:26 by eukwon           ###   ########.fr       */
>>>>>>> 3b9cf95a9aa82eaf7d1fbdf9fe52000dc595cc77
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	to_hex(char *str)
{	
	unsigned char	c;
	unsigned char	div;
	unsigned char	mod;

	c = *str;
	div = c / 16;
	mod = c % 16;
	if (div > 9)
<<<<<<< HEAD
		div = div - 10 + 'a';
	else
		div = div + '0';
	if (mod > 9)
		mod = mod - 10 + 'a';
	else
		mod = mod + '0';
=======
		div = div -10 + 'a';
	else
		div += '0';
	if (mod > 9)
		mod = mod - 10 + 'a';
	else
		mod += '0';
>>>>>>> 3b9cf95a9aa82eaf7d1fbdf9fe52000dc595cc77
	write(1, &div, 1);
	write(1, &mod, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int			i;
	unsigned char		c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c <= 31 || c >= 127)
		{
			write(1, "\\", 2);
			to_hex(&str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
