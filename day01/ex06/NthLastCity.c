/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:03:08 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/25 15:17:55 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char* NthLastCity(struct s_city* city, int n)
{
	if (n < 0)
		return 0;
	struct s_city* result = city;
	while(city)
	{
		if (n < 0)
			result = result->next;
		--n;
		city = city->next;
	}
	if (n > 0)
		return 0;
	return result->name;
}
