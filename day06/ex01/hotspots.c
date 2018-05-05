/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:44:39 by lkaser            #+#    #+#             */
/*   Updated: 2018/05/02 16:08:14 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int selectHotspots(struct s_hotspot** hotspots)
{
	if (!hotspots[0])
		return 0;
	int left = 0;
	int selected = 0;
	for (int right = 1; hotspots[right]; ++right)
	{
		if (hotspots[left]->pos + hotspots[left]->radius > hotspots[right]->pos + hotspots[right]->radius)
			left = right;
		else if (hotspots[left]->pos + hotspots[left]->radius <= hotspots[right]->pos - hotspots[right]->radius)
		{
			++selected;
			left = right;
		}
	}
	return ++selected;
}
