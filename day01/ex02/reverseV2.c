/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:52:03 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/24 14:11:31 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "header.h"

struct s_stack* stackInit(void)
{
	return calloc(1, sizeof(struct s_stack));
}

void* pop(struct s_stack *stack)
{
	if (!stack->item)
		return NULL;
	struct s_item* item = stack->item;
	stack->item = item->next;
	char* word = item->word;
	free(item);
	return word;
}

void push(struct s_stack* stack, char *word)
{	
	struct s_item* item = calloc(1, sizeof(struct s_item));
	item->word = word;
	item->next = stack->item;
	stack->item = item;
}

void printReverseV2(struct s_node* lst)
{
	struct s_stack* stk = stackInit();
	while (lst)
	{
		push(stk, lst->word);
		lst = lst->next;
	}
	while (stk->item)
	{
		char* word = pop(stk);
		write(1, word, strlen(word));
		if (stk->item)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
	}
}
