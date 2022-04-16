/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjung <youjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:00:23 by youjung           #+#    #+#             */
/*   Updated: 2022/01/08 14:01:55 by youjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int x, int y, int ix, int iy)
{	
	if (iy == 0 || iy == y - 1)
	{
		if (ix == 0)
			ft_putchar('A');
		else if (ix == x - 1)
			ft_putchar('C');
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
