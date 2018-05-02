/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:24:40 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/30 14:42:02 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int carPosition(unsigned parkingRow)
{
	int pos = -1;
	if (parkingRow % 2 != 0 && parkingRow > 1)
		return pos;
	while(parkingRow)
	{
		++pos;
		parkingRow /= 2;
	}
	return pos;
}
