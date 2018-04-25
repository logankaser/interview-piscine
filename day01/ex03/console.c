/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:52:03 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/24 16:29:46 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

struct s_stack* stackInit(void)
{
	return calloc(1, sizeof(struct s_stack));
}

int pop(struct s_stack *stack)
{
	if (!stack->item)
		return 0;
	struct s_item* item = stack->item;
	stack->item = item->next;
	int idx = item->idx;
	free(item);
	return idx;
}

void push(struct s_stack* stack, int idx)
{	
	struct s_item* item = calloc(1, sizeof(struct s_item));
	item->idx = idx;
	item->next = stack->item;
	stack->item = item;
}

char* console(void)
{
	char msg[512] = {0};
	struct s_stack* stk = stackInit();
	char line[256];
	char* l = line;
	size_t size = 256;
	int ret = 0;
	printf("> ");
	while ((ret = getline(&l, &size, stdin)) != -1)
	{
		line[ret - 1] = '\0';
		if (strcmp("SEND", line) == 0)
			return strdup(msg);
		if (strcmp("UNDO", line) == 0)
		{
			pop(stk);
			if (stk->item)
				msg[stk->item->idx] = '\0';
			printf("> ");
			continue;
		}
		int i = stk->item ? stk->item->idx : 0;
		for (int j = 0; line[j]; ++j)
			msg[i++] = line[j];
		push(stk, i);
		memset(line, 0, 256);
		printf("> ");
	}
	return NULL;
}
