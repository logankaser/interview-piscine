/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:37:35 by lkaser            #+#    #+#             */
/*   Updated: 2018/05/01 20:01:53 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char* leftShift(char* a, int k)
{
	for (int i = 1; i < 6 + k; ++i)
	{
		if (i < 6 && i - k >= 0)
			a[i - k] = a[i];
		else if (i >= 6)
			a[i - k] = '0';
	}
	return a;
}

char* rightShift(char* a, int k)
{
	char c = a[0];
	for (int i = 5; i >= -k; --i)
	{
		if (i >= 0 && i + k < 6)
			a[i + k] = a[i];
		else if (i < 0)
			a[i + k] = c;
	}
	return a;
}

int toInt(char* bits)
{
	int sign = 0;
	int result = 0;
	if (bits[0] == '1')
	{
		sign = 1;
		result = 1;
	}
	for (int i = 5; i >= 1; --i)
		if (sign ? bits[i] == '0' : bits[i] == '1')
			result += 1 << (5 - i);
	if (sign)
		result *= -1;
	return result;
}
