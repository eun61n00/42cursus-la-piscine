/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:14:00 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/24 17:42:46 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_whitespace(char c);
int	check_base(char *base);
int	is_base(char c, char *base);
int	check_start_idx(char *str, int *sign);
int	convert_from_base(char *nbr, char *base_from);
int	get_base_num(char *base_to);

int	get_base_num(char *base_to)
{
	int	base_num;

	base_num = 0;
	while (base_to[base_num])
		base_num++;
	return (base_num);
}

int	get_result_digit(int decimal, int base_num)
{
	int	digit;

	digit = 1;
	while (decimal / base_num > 0)
	{
		decimal /= base_num;
		digit++;
	}
	if (decimal < 0)
		return (digit + 1);
	else
		return (digit);
}

void	convert_to_base(long decimal, char *base_to, char *result, int *idx)
{
	int	base_num;

	base_num = get_base_num(base_to);
	if (decimal < 0)
	{
		result[0] = '-';
		*idx = *idx + 1;
		convert_to_base(-decimal, base_to, result, idx);
	}
	else
	{
		if (decimal / base_num > 0)
		{
			convert_to_base(decimal / base_num, base_to, result, idx);
		}
		result[*idx] = base_to[decimal % base_num];
		*idx = *idx + 1;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	decimal;
	int		base_num;
	char	*result;
	int		digit;
	int		idx;

	idx = 0;
	if (!check_base(base_from) || !check_base(base_to))
	{
		return (NULL);
	}
	decimal = convert_from_base(nbr, base_from);
	base_num = get_base_num(base_to);
	digit = get_result_digit(decimal, base_num);
	result = (char *)malloc(sizeof(char) * digit + 1);
	convert_to_base(decimal, base_to, result, &idx);
	result[idx] = '\0';
	return (result);
}
