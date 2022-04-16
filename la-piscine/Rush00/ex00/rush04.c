/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjung <youjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:01:09 by youjung           #+#    #+#             */
/*   Updated: 2022/01/09 11:27:52 by youjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int x, int y, int ix, int iy)
{	
	if (ix == 0 || ix == x - 1 || iy == 0 || iy == y - 1)
	{
		if (ix == 0 && iy == 0)
			ft_putchar('A');
		else if ((ix == 0 && iy == y - 1) || (ix == x - 1 && iy == 0))
			ft_putchar('C');
		else if ((ix == x - 1 && iy == y - 1))
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else
	{
		if (ix == 0 || ix == x - 1)
			ft_putchar('B');
		else
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
