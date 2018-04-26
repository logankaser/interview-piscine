/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:15:03 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/25 19:43:15 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	insertionSort(struct s_player* players[])
{
	int i, j;
	struct s_player* p;
	for (i = 1; players[i]; i++)
		for (j = i; j > 0 && players[j - 1]->score < players[j]->score; j--)
		{
			p = players[j];
			players[j] = players[j - 1];
			players[j - 1] = p;
		}
}
