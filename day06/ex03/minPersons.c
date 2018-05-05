/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:54:21 by lkaser            #+#    #+#             */
/*   Updated: 2018/05/03 17:12:45 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int minPersons(int elements, int minPercentage)
{
	if (minPercentage == 100)
		return elements + 1;
	if (minPercentage <= 1)
		return -1;
	double e = elements;
	for (int people = 1; people < elements; ++people)
	{
		double p = 1.0;
		for (double x = elements; x > e - people; --x)
			p *= x / e;
		if ((1 - p) * 100 >= minPercentage)
			return people;
	}
	return -1;
}
