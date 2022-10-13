#include "custom.h"

t_node	*createNode(unsigned int key, char *str)
{
	t_node	*newNode;

	newNode = (t_node *) malloc(sizeof(t_node));
	newNode->key = key;
	newNode->value = str;
	newNode->next = 0;
	return (newNode);
}

int	hashFunction(unsigned int key)
{
	key += 59;
	return (key % BUCKET_SIZE);
}

t_bucket	*dict_add(unsigned int key, char *value, t_bucket *dict)
{
	int		hash;
	t_node	*newNode;
	char	*newNode_value;

	hash = hashFunction(key);
	newNode = createNode(key, value);
	newNode_value = newNode->value;
	if (dict[hash].count == 0)
	{
		dict[hash].count = 1;
		dict[hash].head = newNode;
	}
	else
	{
		newNode->next = dict[hash].head;
		dict[hash].head = newNode;
		dict[hash].count++;
	}
	return (dict);
}
