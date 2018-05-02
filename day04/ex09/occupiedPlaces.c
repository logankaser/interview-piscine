/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 13:46:23 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/30 14:20:26 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int occupiedPlaces(unsigned parkingRow)
{
	int count;
	for (count = 0; parkingRow; ++count)
		parkingRow &= parkingRow - 1;
	return count;
}
