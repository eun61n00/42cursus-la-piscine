/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 08:51:09 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/22 15:41:30 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

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

void	ft_swap(char **argv, int i, int j)
{
	char	*tmp;

	tmp = argv[j];
	argv[j] = argv[i];
	argv[i] = tmp;
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	idx;

	i = argc - 1;
	while (i > 0)
	{
		j = 1;
		while (j < i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				ft_swap(argv, j, j + 1);
			j++;
		}
		i--;
	}
	idx = 1;
	while (argc > 1)
	{
		ft_putstr(argv[idx++]);
		argc--;
		write(1, "\n", 1);
	}
}
