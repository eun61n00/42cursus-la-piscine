/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:13:35 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/27 15:33:26 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **tab, int i, int j)
{
	char	*tmp;

	tmp = tab[j];
	tab[j] = tab[i];
	tab[i] = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (tab[len])
		len++;
	while (j < len - 1)
	{
		i = 0;
		while (i < len - j - 1)
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(tab, i, i + 1);
			}
			i++;
		}
		j++;
	}
}
