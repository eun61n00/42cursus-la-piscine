/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:19:13 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/18 15:44:42 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
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

int	check_start_index(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
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

int	ft_atoi_base(char *str, char *base)
{
	int	idx;
	int	sign;
	int	base_num;
	int	result;

	base_num = 0;
	if (!check_base(base))
		return (0);
	while (base[base_num])
		base_num++;
	sign = 1;
	idx = check_start_index(str, &sign);
	result = 0;
	while (is_base(str[idx], base) != -1)
	{
		result = result * base_num + is_base(str[idx], base);
		idx++;
	}
	return (result * sign);
}
