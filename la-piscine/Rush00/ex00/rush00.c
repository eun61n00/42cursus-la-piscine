/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:11:54 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/09 09:12:11 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int x, int y, int ix, int iy)
{	
	if (iy == 0 || iy == y - 1)
	{
		if (ix == 0 || ix == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (ix == 0 || ix == x - 1)
			ft_putchar('|');
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
