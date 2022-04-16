/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:55:41 by junsoh            #+#    #+#             */
/*   Updated: 2022/01/23 20:30:56 by junsoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom.h"

t_bucket	*make_dict(char **key_pairs)
{
	char		**k_v;
	t_bucket	*dict;
	int			i;

	dict = (t_bucket *) malloc(sizeof(t_bucket) * (BUCKET_SIZE + 1));
	i = 0;
	while (i < 5)
	{
		dict[i].count = 0;
		dict[i].head = NULL;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		k_v = ft_split(k_v, key_pairs[i], ':');
		dict = dict_add(ft_atoi(k_v[0]), k_v[1], dict);
		i++;
	}
	return (dict);
}

t_node	*find_param(t_bucket *dict, unsigned int key)
{
	int			hash;
	t_node		*curr_node;
	char		*value;

	hash = hashFunction(key);
	curr_node = dict[hash].head;
	value = (curr_node->value);
	while (curr_node != 0)
	{
		if (curr_node->key == key)
			return (curr_node);
		else
			curr_node = curr_node->next;
	}
	return (0);
}