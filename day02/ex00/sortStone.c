/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:35:16 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/25 19:04:17 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void bubbleSort(struct s_stone** array, int len)
{
	int	i;
	struct s_stone* temp;

	i = 0;
	while (i < len)
	{
		if (array[i]->size > array[i + 1]->size)
		{
			temp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = temp;
			i = 0;
		}
		else
			++i;
	}
}

void sortStones(struct s_stone** stone)
{
	int size = 0;
	for (struct s_stone* s = *stone; s->next; s = s->next)
		++size;
	struct s_stone* stoneArray[size];
	stoneArray[0] = *stone;
	int group = (*stone)->size;
	int i = 0;
	for (struct s_stone* s = *stone; s; s = s->next)
	{
		if (s->size != group)
		{
			stoneArray[++i] = s;
			group = s->size;
		}
	}
	bubbleSort(stoneArray, i);
	struct s_stone* s = stoneArray[0];
	int j = 0;
	while (j < i)
	{
		if (!s->next || s->size != s->next->size || s->next == stoneArray[j + 1])
			s->next = stoneArray[++j];
		s = s->next;
	}
	while (s->next && s->size == s->next->size)
		s = s->next;
	s->next = 0;
	*stone = stoneArray[0];
}
