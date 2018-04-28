/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:10:49 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/26 12:36:20 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int min(int a, int b)
{
	return (a < b ? a : b);
}

typedef struct s_player* type;

static void bottomUp(type A[], int left, int right, int end, type B[])
{
	int i = left;
	int j = right;
	for (int k = left; k < end; ++k)
	{
		if (i < right && (j >= end || A[i]->score <= A[j]->score))
		{
			B[k] = A[i];
			++i;
		}
		else
		{
			B[k] = A[j];
			++j;
		}
	}
}

static void copy(type B[], type A[], int n)
{
	for (int i = 0; i < n; ++i)
		A[i] = B[i];
}

// Uses VLA for simplicity
static void sort(type array[], int n)
{
	type work[n];
	for (int width = 1; width < n; width = 2 * width)
	{
		for (int i = 0; i < n; i += 2 * width)
			bottomUp(array, i, min(i + width, n), min(i + width * 2, n), work);
		copy(work, array, n);
	}
}

type* mergeSort(type players[])
{
	int len = 0;
	while (players[len])
		++len;
	--len;
	sort(players, len);
	return players;
}

