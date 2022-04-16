/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:36:50 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/17 13:20:50 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_len(char *arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

int	return_j(char *str, char *to_find, int to_find_len, int i)
{
	int	j;

	j = 0;
	while (j < to_find_len)
	{
		if (str[i + j] == to_find[j])
			j++;
		else
			break ;
	}
	if (j == to_find_len)
		return (j);
	else
	{
		return (0);
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int	to_find_len;
	int	i;
	int	j;

	to_find_len = get_len(to_find);
	if (to_find_len == 0)
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = return_j(str, to_find, to_find_len, i);
			if (j != 0)
				return (str + i);
		}
		i++;
	}
	return (0);
}
