/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:42:49 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/24 22:13:45 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"

struct s_string* stringInit(void)
{
	return calloc(1, sizeof(struct s_string));
}

int stringAppend(struct s_string* s, char *add)
{
	int len = strlen(add);

	if (len > s->capacity - s->length)
	{
		s->capacity = (s->length + len) * 2;
		char* new = realloc(s->content, s->capacity);
		if (!new)
			return -1;
		s->content = new;
	}
	memset(s->content + s->length, 0, s->capacity - s->length);
	strcpy(s->content + s->length, add);
	s->length += len;
	return 0;
}

static int head_part(char* wrd)
{
	int i = 0;
	while (*wrd && *wrd != ',' && *wrd != '>')
	{
		++i;
		++wrd;
	}
	return i;
}

char* decompress(char* comp)
{
	// Create header map

	char* header[256] = {0};
	++comp;
	int index = 1;
	while (*comp != '>')
	{
		int len = head_part(comp);
		char tmp = comp[len];
		comp[len] = '\0';
		header[index++] = strdup(comp);
		comp[len] = tmp;
		comp += len;
		if (*comp == ',')
			++comp;
	}

	// Decompress

	struct s_string* s = stringInit();

	while (*comp)
    {
		int i = 0;
        while (comp[i] != '@' && comp[i])
			++i;
		comp[i] = '\0';
		stringAppend(s, comp);
		comp += i;

		++comp;
		if (*comp)
		{
			stringAppend(s, header[(int)*comp]);
			++comp;
		}
    }

	for (int i = 0; i < 256; ++i)
		free(header[i]);
	return s->content;
}

void	test(char* comp)
{
	printf("%s", decompress(comp));
}
