/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:47:25 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/24 09:17:18 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "header.h"


int	searchPrice(struct s_art** arts, int n, char* name)
{
	int low = 0;
	int high = n;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int c = strcmp(name, arts[mid]->name);
		if (c == 0)
			return arts[mid]->price;
		else if (c < 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

void	test(struct s_art** arts)
{
	int size = 0;
	while (arts[size])
		++size;
	--size;
	printf("Price for Mona Lisa is %i\n", searchPrice(arts, size, "Mona Lisa"));
	printf("Price for the movement is %i\n", searchPrice(arts, size, "the movement"));
	printf("Price for the puritan is %i\n", searchPrice(arts, size, "the puritan"));
	printf("Price for ft_does_not_exist is %i\n", searchPrice(arts, size, "ft_does_not_exist"));
}
