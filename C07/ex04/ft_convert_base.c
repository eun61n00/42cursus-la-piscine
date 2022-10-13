/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:26:31 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/24 17:35:12 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (is_whitespace(base[i]))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_start_idx(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_whitespace(str[i]))
			i++;
		else
			break ;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	convert_from_base(char *nbr, char *base_from)
{
	int	idx;
	int	sign;
	int	base_num;
	int	result;

	base_num = 0;
	if (!check_base(base_from))
		return (0);
	while (base_from[base_num])
		base_num++;
	sign = 1;
	idx = check_start_idx(nbr, &sign);
	result = 0;
	while (is_base(nbr[idx], base_from) != -1)
	{
		result = result * base_num + is_base(nbr[idx], base_from);
		idx++;
	}
	return (result * sign);
}
