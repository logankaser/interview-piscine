/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:42:49 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/24 21:07:14 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

#define NULL_GUARD(a) if(!(a)) return (0);

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

int	dictInsert(struct s_dict *dict, char *key, int value)
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

int dictSearch(struct s_dict* dict, char *key)
{
	size_t index = hash(key) % dict->capacity;
	struct s_item* item = dict->items[index];
	while (item)
	{
		if (strcmp(item->key, key) == 0)
			return item->value;
		item = item->next;
	}
	return -1;
}

static int word_end(char* wrd)
{
	int i = 0;
	while (*wrd && isalpha(*wrd))
	{
		++i;
		++wrd;
	}
	return i;
}

char* compress(char* book, struct s_dict* dict)
{
	long B = strlen(book);
	int H = 0;
	int index = 1;
	char* compressed;

	// Header
	for (int i = 0; i < dict->capacity; ++i)
	{
		struct s_item* item = dict->items[i];
		while (item)
		{
			H += strlen(item->key);
			item->value = index++;
			item = item->next;
		}
	}
	H += index - 1; // index -1 is number of commas
	H += 2; // Angle brackets
	NULL_GUARD(compressed = calloc(H + B, 1));
	compressed[0] = '<';
	index = 1;
	for (int i = 0; i < dict->capacity; ++i)
	{
		struct s_item* item = dict->items[i];
		while (item)
		{
			strcpy(compressed + index, item->key);
			index += strlen(item->key);
			compressed[index] = ',';
			++index;
			item = item->next;
		}
	}
	compressed[index - 1] = '>';

	// Compression

	while (*book)
	{
		if (!isalpha(*book))
		{
			compressed[index++] = *book++;
			continue;
		}
		int we = word_end(book);
		char tmp = book[we];
		book[we] = '\0';
		char comp;
		if ((comp = dictSearch(dict, book)) != -1)
		{
			memcpy(compressed + index, "@", 1);
			index += 1;
			compressed[index++] = comp;
		}
		else
		{
			for (int i = 0; i < we; ++i)
				compressed[index++] = book[i];
		}
		book[we] = tmp;
		book += we;
	}
	char* resized = strdup(compressed);
	free(compressed);
	return resized;
}

void	test(char* bible, struct s_dict* dict)
{
	printf("%s\n", compress(bible, dict));
}
