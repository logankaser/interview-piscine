/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 09:29:59 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/24 09:19:29 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

typedef struct s_art* type;

static int	compare(const void* a, const void* b)
{
	return strcmp(((type)a)->name, ((type)b)->name);
}

static void	sift_down(type array[], int root, int bottom)
{
	int max_child = root * 2 + 1;

	if (max_child < bottom)
	{
		if (compare(array[max_child + 1], array[max_child]) > 0)
			max_child += 1;
	}
	else
	{
		if (max_child > bottom)
			return;
	}

	if (compare(array[root], array[max_child]) >= 0)
		return;

	type tmp = array[root];
	array[root] = array[max_child];
	array[max_child] = tmp;

	sift_down(array, max_child, bottom);
}

void	ft_heapsort(type array[], int size)
{
	int i;
	type tmp;

	for (i = size / 2; i > -1; --i)
	{
		sift_down(array, i, size - 1);
	}
	for (i = size - 1; i > 0; --i)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		sift_down(array, 0, i - 1);
	}
}

void	sortArts(struct s_art** arts)
{
	int size = 0;
	while (arts[size])
		++size;
	ft_heapsort(arts, size);
}

void	test(struct s_art **arts)
{
	sortArts(arts);
	while (*arts)
	{
		printf("%s => %i\n", (*arts)->name, (*arts)->price);
		++arts;
	}
}
