/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:08:26 by junsoh            #+#    #+#             */
/*   Updated: 2022/01/23 20:29:56 by junsoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom.h"

int	file_read(char *path, char *buf, int buf_len)
{
	int	f;
	int	file_len;

	f = open(path, O_RDONLY);
	if (f < 0)
	{
		print_err(-1);
		return (-1);
	}
	else
	{
		file_len = read(f, buf, buf_len);
		close(f);
		return (file_len);
	}
}

char	**parse_file(char **dest, char *dict_path)
{
	char				dict_str[MAX_BUF];
	char				trim_str[MAX_BUF];
	int					file_len;

	file_len = file_read(dict_path, dict_str, MAX_BUF);
	ft_trim(trim_str, dict_str);
	dest = ft_split(dest, trim_str, '\n');
	return (dest);
}