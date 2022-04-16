/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:51:21 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/26 10:38:30 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *sep)
{
	int	i;
	int	sep_len;

	i = 0;
	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	while (i <= sep_len)
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	init_var(int *i, int *j, int *start_idx, int *word_len)
{
	*i = 0;
	*j = 0;
	*word_len = 0;
	*start_idx = 0;
}

void	split(char *str, char **word_arr_lst, char *charset)
{
	int	i;
	int	j;
	int	start_idx;
	int	word_len;

	init_var(&i, &j, &start_idx, &word_len);
	while (str[i])
	{
		if (!is_sep(str[i], charset) && is_sep(str[i + 1], charset))
		{
			word_len++;
			word_arr_lst[j] = ft_strndup(&str[start_idx], word_len);
			j++;
		}
		else if (is_sep(str[i], charset) && !is_sep(str[i + 1], charset))
		{
			word_len = 0;
			start_idx = i + 1;
		}
		else if (!(is_sep(str[i], charset)))
			word_len++;
		i++;
	}
	word_arr_lst[j] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**word_arr_lst;
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	if (!(is_sep(str[0], charset)))
		cnt++;
	while (str[i])
	{
		if (is_sep(str[i], charset) && !(is_sep(str[i + 1], charset)))
			cnt++;
		i++;
	}
	word_arr_lst = (char **)malloc(sizeof(char *) * cnt + 1);
	if (word_arr_lst == NULL)
		return (NULL);
	split(str, word_arr_lst, charset);
	return (word_arr_lst);
}
