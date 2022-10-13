/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takang <takang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:51:52 by takang            #+#    #+#             */
/*   Updated: 2022/01/09 12:56:20 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int x, int y, int ix, int iy)
{
	if (iy == 0 && (ix == 0 || ix + 1 == x))
	{
		ft_putchar('A');
	}
	else if (iy + 1 == y && (ix == 0 || ix + 1 == x))
	{
		ft_putchar('C');
	}
	else
	{
		if (ix == 0 || ix + 1 == x || iy + 1 == y || iy == 0)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
	}	
}

void	rush( int x, int y)
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
