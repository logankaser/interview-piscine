/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:42:49 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/23 14:57:28 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

# define NULL_GUARD(a) if(!(a)) return (0);

// FVN-1a 64 bit
size_t hash(char* str)
{
	size_t result = 14695981039346656037ULL;
	while (*str)
	{
		result = *str ^ result;
		result *= 1099511628211ULL;
		++str;	
	}
	return result;
}

struct s_dict* dictInit(int capacity)
{
	struct s_dict* dict;
	NULL_GUARD(dict = malloc(sizeof(struct s_dict)))
	NULL_GUARD(dict->items = calloc(capacity, sizeof(struct item*)))
	dict->capacity = capacity;
	return dict;
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	size_t index = hash(key) % dict->capacity;
	if (!dict->items[index])
	{
		NULL_GUARD(dict->items[index] = malloc(sizeof(struct s_item)))
		NULL_GUARD(dict->items[index]->key = strdup(key))
		dict->items[index]->value = value;
		dict->items[index]->next = NULL;
	}
	else
	{
		struct s_item* item = dict->items[index];
		while (item->next)
			item = item->next;
		NULL_GUARD(item->next = malloc(sizeof(struct s_item)))
		NULL_GUARD(item->next->key = strdup(key))
		item->next->value = value;
		item->next->next = NULL;
	}
	return 1;
}

struct s_art* dictSearch(struct s_dict* dict, char *key)
{
	size_t index = hash(key) % dict->capacity;
	struct s_item* item = dict->items[index];
	while (item)
	{
		if (strcmp(item->key, key) == 0)
			return item->value;
		item = item->next;
	}
	return NULL;
}

int	searchPrice(struct s_dict* dict, char* name)
{
	struct s_art* found = dictSearch(dict, name);
	if (found == NULL)
		return -1;
	return found->price;
}

void	test(struct s_art** arts)
{
	int size = 0;
	while (arts[size])
		++size;
	--size;
	struct s_dict* table = dictInit(size);
	for (int i = 0; i < size; ++i)
		dictInsert(table, arts[i]->name, arts[i]);
	printf("Mona Lisa: %i\n", searchPrice(table, "Mona Lisa"));
	printf("the movement: %i\n", searchPrice(table, "the movement"));
	printf("the puritan: %i\n", searchPrice(table, "the puritan"));
	printf("ft_does_not_exist: %i\n", searchPrice(table, "ft_does_not_exist"));
}
