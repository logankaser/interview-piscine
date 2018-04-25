/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:37:19 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/24 13:33:52 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include <unistd.h>

char* precious(int* text, int size)
{
	const char* key_src = CS;

	struct s_node* node = calloc(1, sizeof(struct s_node));
	struct s_node* head = node;
	node->c = key_src[0];
	for (unsigned i = 1; i < sizeof(CS) - 1; ++i)
	{
		node->next = calloc(1, sizeof(struct s_node));
		node->next->prev = node;
		node->next->c = key_src[i];
		node = node->next;
	}
	head->prev = node;
	node->next = head;
	node = head;
	char* result = calloc(size + 1, 1);
	for (int i = 0; i < size; ++i)
	{
		for (int j = abs(text[i]); j != 0; --j)
		{
			if (text[i] > 0)
				node = node->next;
			else
				node = node->prev;
		}
		result[i] = node->c;
	}
	return result;
}

void	test(int* text, int size)
{
	printf("%s\n", precious(text, size));
}
