/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 08:53:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/30 10:06:54 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char* getSum(char* a, char* b)
{
	char c[6] = "000000";
	for (int i = 5; i >= 0; --i)
	{
		if (a[i] - '0' && b[i] - '0')
			c[i - 1] = '1';
		else if (a[i] - '0' || b[i] - '0')
		{
			if (c[i] - '0')
			{
				c[i] = '0';
				--i;
			}
			c[i] = '1';
		}
	}
	for (int i = 5; i >= 0; --i)
		a[i] = c[i];
	return a;
}

int toInt(char* bits)
{
	int result = 0;
	for (int i = 5; i >= 0; --i)
	{
		if (bits[i] - '0')
			result += 1 << (5 - i);
	}
	return result;
}
