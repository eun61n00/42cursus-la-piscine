/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:57:14 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/27 15:30:28 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap(char **tab, int i, int j)
{
	char	*tmp;

	tmp = tab[j];
	tab[j] = tab[i];
	tab[i] = tmp;
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(tab, i, i + 1);
			}
			i++;
		}
		j++;
	}
}
