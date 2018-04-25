/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:10:36 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/25 11:30:15 by lkaser           ###   ########.fr       */
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
	int energy = item->energy;
	free(item);
	return energy;
}

void push(struct s_stack* stack, int energy)
{	
	struct s_item* item = calloc(1, sizeof(struct s_item));
	item->energy = energy;
	item->next = stack->item;
	stack->item = item;
}

struct s_tank* initTank(void)
{
	struct s_tank* tank = calloc(1, sizeof(struct s_tank));
	tank-
}

void tankPush(struct s_tank* tank, int energy)

int tankPop(struct s_tank* tank)
