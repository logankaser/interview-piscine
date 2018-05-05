/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:22:36 by lkaser            #+#    #+#             */
/*   Updated: 2018/05/03 10:42:18 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


double probabilityWin(double initial, double target, int game)
{
	if (initial >= target)
		return 1.0;
	if (game < 1 || initial < 0.000001)
		return 0.0;
	--game;
	double r = (18.0 / 37.0) * probabilityWin(initial * 2, target, game);
	double g = (1.0 / 37.0) * probabilityWin(initial / 2, target, game);
	return r + g;
}
