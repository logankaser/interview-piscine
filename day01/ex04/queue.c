/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 08:53:02 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/25 09:54:12 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct s_queue* queueInit(void)
{
	return calloc(1, sizeof(struct s_queue));
}

char* dequeue(struct s_queue* queue)
{
	if (!queue->last)
		return NULL;
	struct s_node* tmp = queue->last;
	if (tmp->next)
		queue->last = tmp->next;
	else
		queue->last = queue->first = NULL;
	char* msg = tmp->message;
	free(tmp);
	return msg;
}

void enqueue(struct s_queue* queue, char* message)
{
	struct s_node* new = calloc(1, sizeof(struct s_node));
	new->message = message;
	if (!queue->first)
		queue->first = queue->last = new;
	else
	{
		queue->first->next = new;
		queue->first = new;
	}
}

char* peek(struct s_queue* queue)
{
	if (!queue->last)
		return NULL;
	return queue->last->message;
}

int isEmpty(struct s_queue* queue)
{
	if (queue->last)
		return 0;
	return 1;
}

void test(void)
{
	struct s_queue* q = queueInit();
	enqueue(q, "apple");
	enqueue(q, "orange");
	printf("%s\n", peek(q));
	dequeue(q);
	printf("%s\n", peek(q));
	printf("%s\n", dequeue(q));
	printf("%i\n", isEmpty(q));
}
