/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:14:11 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/30 14:37:39 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int carPosition(unsigned parkingRow)
{
	int pos = -1;
	if (parkingRow & -1)
		return pos;
	for (int i = 0; i < 32; ++i)
		if (parkingRow >> i == 1)
			pos = i;
	return pos;	
}
