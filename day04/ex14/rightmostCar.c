/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:53:27 by lkaser            #+#    #+#             */
/*   Updated: 2018/05/01 10:20:49 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int rightmostCar(unsigned parkingRow)
{
	unsigned mask = 1U;
	for (int i = 0; i < 32; ++i)
		if (parkingRow & (mask << i))
			return i;
	return -1;
}
