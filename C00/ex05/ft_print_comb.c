/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: eukwon <eukwon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:21:50 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/07 18:40:57 by eukwon           ###   ########.fr       */
=======
/*   By: eukwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 08:42:14 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/08 09:42:06 by eukwon           ###   ########.fr       */
>>>>>>> bee50a83832e3d642ea4199ff089f4d495be0b56
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	ft_print_comb(void)
{
	char	comb[3];

	comb[0] = '0';
	while (comb[0] <= '7')
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= '8')
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= '9')
			{
				write(1, comb, 3);
				if (comb[0] != '7')
				{
					write(1, ", ", 2);
				}
<<<<<<< HEAD
				c++;
			}
			b++;
		}
		a++;
=======
				comb[2]++;
			}
			comb[1]++;
		}
		comb[0]++;
>>>>>>> bee50a83832e3d642ea4199ff089f4d495be0b56
	}
}
