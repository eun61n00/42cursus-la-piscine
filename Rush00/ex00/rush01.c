/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:55:51 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/09 12:42:00 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int x, int y, int ix, int iy)
{	
	if (ix == 0 || ix == x - 1 || iy == 0 || iy == y - 1)
	{
		if (ix == 0 && iy == 0)
		{
			ft_putchar('/');
		}
		else if ((ix == 0 && iy == y - 1) || (ix == x - 1 && iy == 0))
		{
			ft_putchar('\\');
		}
		else if (ix == x - 1 && iy == y - 1)
		{
			ft_putchar('/');
		}
		else
		{
			ft_putchar('*');
		}
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	ix;
	int	iy;

	ix = 0;
	iy = 0;
	while (iy < y)
	{
		while (ix < x)
		{
			check(x, y, ix, iy);
			ix++;
		}
		ft_putchar('\n');
		ix = 0;
		iy++;
	}
}
