/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:53:27 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/30 15:44:55 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int leftmostCar(unsigned parkingRow)
{
	for (int i = 31; i >= 0; --i)
		if ((parkingRow >> i) && 1)
			return i;
	return -1;
}
