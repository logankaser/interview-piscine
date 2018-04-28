/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:48:59 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/26 11:09:14 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int partition(struct s_player* players[], int lo , int hi)
{
	struct s_player* pivot = players[hi];
	int i = lo - 1;
	struct s_player* tmp;
	for (int j = lo; j < hi; ++j)
	{
		if (players[j]->score < pivot->score)
		{
			++i;
			tmp = players[i];
			players[i] = players[j];
			players[j] = tmp;
		}
	}
	tmp = players[i + 1];
	players[i + 1] = players[hi];
	players[hi] = tmp;
	return i + 1;
}

static void sort(struct s_player* players[], int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(players, lo, hi);
		sort(players, lo, p - 1);
		sort(players, p + 1, hi);
	}
}

void quickSort(struct s_player** players)
{
	int len = 0;
	while (players[len])
		++len;
	--len;
	sort(players, 0, len);
}
