/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:36:39 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/26 12:59:01 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"

typedef unsigned char type;

static type maxArray(type array[], int n)
{
	type max = 0;
	for (; n >= 0; --n)
		if (array[n] > max)
			max = array[n];
	return max;
}

void countSort(type array[], int n)
{
	type max = maxArray(array, n);
	type hist[max];
	memset(hist, 0, max);

	int i = 0;
	for (i = 0; i < n; ++i)
		hist[array[i]] += 1;
	int nbr = 0;
	i = 0;
	while (i <= n)
	{
		while (hist[nbr] > 0)
		{
			array[i] = nbr;
			hist[nbr] -= 1;
			++i;
			if (i > n)
				break;
		}
		++nbr;
	}
}
