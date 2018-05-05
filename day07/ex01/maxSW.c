/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:10:51 by lkaser            #+#    #+#             */
/*   Updated: 2018/05/04 16:17:27 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "header.h"

struct s_deque* dequeInit(void)
{
	return calloc(1, sizeof(struct s_deque));
}

void pushFront(struct s_deque* deque, int value)
{
	struct s_dequeNode* new = calloc(1, sizeof(struct s_dequeNode));
	new->value = value;
	if (deque->first)
	{
		deque->first->next = new;
		new->prev = deque->first;
	}
	else
		deque->last = new;
	deque->first = new;
}

void pushBack(struct s_deque* deque, int value)
{
	struct s_dequeNode* new = calloc(1, sizeof(struct s_dequeNode));
	new->value = value;
	if (deque->last)
	{
		deque->last->prev = new;
		new->next = deque->last;
	}
	else
		deque->first = new;
	deque->last = new;
}

int popFront(struct s_deque* deque)
{
	if (!deque->first)
		return INT_MIN;
	struct s_dequeNode* first = deque->first;
	if (first->prev)
	{
		deque->first = first->prev;
		deque->first->next = NULL;
	}
	else
		deque->first = deque->last = NULL;
	int tmp = first->value;
	free(first);
	return tmp;
}

int popBack(struct s_deque* deque)
{
	if (!deque->last)
		return INT_MIN;
	struct s_dequeNode* last = deque->last;
	if (last->next)
	{
		deque->last = last->next;
		deque->last->prev = NULL;
	}
	else
		deque->first = deque->last = NULL;
	int tmp = last->value;
	free(last);
	return tmp;
}

struct s_max* maxSW(int array[], int n, int k)
{
	if (k >= n || k < 0 || n < 1)
		return NULL;
	struct s_max* output = malloc(sizeof(struct s_max));
	output->length = 1 + n - k;
	output->max = malloc(sizeof(int) * n);
	struct s_deque* window = dequeInit();
	for (int i = 0; i < k; ++i)
	{
		while (window->last != NULL && array[window->last->value] <= array[i])
			popBack(window);
		pushBack(window, i);
	}
	for (int i = k; i < n; ++i)
	{
		output->max[i - k] = array[window->first->value];
		while (window->first != NULL && window->first->value <= i - k)
			popFront(window);
		while (window->last != NULL && array[window->last->value] <= array[i])
			popBack(window);
		pushBack(window, i);
	}
	output->max[n - k] = array[window->first->value];
	return output;
}
