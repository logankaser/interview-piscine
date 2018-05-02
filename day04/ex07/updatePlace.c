/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:43:45 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/30 13:37:36 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned updatePlace(unsigned parkingRow, int pos, int value)
{
	return parkingRow ^ ((-value ^ parkingRow) & (1 << pos));
}
