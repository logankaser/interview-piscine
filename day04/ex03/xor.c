/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 11:52:54 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/30 12:00:27 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char* getXor(char* a, char* b)
{
	for (int i = 0; i < 6; ++i)
		if (a[i] == b[i])
			a[i] = '0';
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
