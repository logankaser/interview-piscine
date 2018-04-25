/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:10:36 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/25 14:54:12 by lkaser           ###   ########.fr       */
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
	if (!stack->elem)
		return 0;
	struct s_elem* item = stack->elem;
	stack->elem = item->next;
	int energy = item->energy;
	free(item);
	stack->sum -= energy;
	return energy;
}

void push(struct s_stack* stack, int energy)
{	
	struct s_elem* item = calloc(1, sizeof(struct s_elem));
	item->energy = energy;
	item->next = stack->elem;
	stack->elem = item;
	stack->sum += energy;
}

struct s_tank* initTank(void)
{
	struct s_tank* tank = calloc(1, sizeof(struct s_tank));
	tank->n = 1;
	tank->stacks = calloc(1, sizeof(struct s_stack*));
	tank->stacks[0] = stackInit();
	return tank;
}

void tankPush(struct s_tank* tank, int energy)
{
	if (tank->stacks[tank->n - 1]->sum + energy > 1000)
	{
		struct s_stack** new = calloc(tank->n + 1, sizeof(struct s_stack*));
		memcpy(new, tank->stacks, sizeof(struct s_stack*) * (tank->n + 1));
		free(tank->stacks);
		tank->stacks = new;
		tank->stacks[tank->n] = stackInit();
		push(tank->stacks[tank->n], energy);
		tank->n++;
	}
	else
		push(tank->stacks[tank->n - 1], energy);
}

int tankPop(struct s_tank* tank)
{
	int energy = pop(tank->stacks[tank->n - 1]);
	if (tank->stacks[tank->n - 1]->sum == 0 && tank->n > 1)
	{
		free(tank->stacks[tank->n - 1]);
		tank->n -= 1;
	}
	return energy;
}

void	test(void)
{
	struct s_tank* tank = initTank();

	printf("Push 100 * 21\n");
	for (int i = 0; i < 21; ++i)
		tankPush(tank, 100);
	for (int i = 0; i < 20; ++i)
	{
		printf("Number of stacks: %i\n", tank->n);
		printf("Pop %i: %i\n", i + 1, tankPop(tank));
	}
}
