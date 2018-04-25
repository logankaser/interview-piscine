/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 09:30:22 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/23 09:30:30 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"

int	searchPrice(struct s_art **arts, char* name)
{
	for (unsigned i = 0; arts[i]; ++i)
	{
		if (strcmp(name, arts[i]->name) == 0)
			return arts[i]->price;
	}
	return -1;
}
