/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:07:45 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/30 10:34:22 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void negate(char* s)
{
	*s = (!(*s - '0')) + '0';
}

char* getOr(char* a, char* b)
{
	int na = 0;
	int nb = 0;
	if (a[0] == '~')
	{
		na = 1;
		++a;
	}
	if (b[0] == '~')
	{
		nb = 1;
		++b;
	}
	for (int i = 3; i >= 0; --i)
	{
		if (na)
			negate(a + i);
		if (nb)
			negate(b + i);
		a[i] = (a[i] - '0' || b[i] - '0') + '0';
	}
	return a;
}

char* getAnd(char* a, char* b)
{
	int na = 0;
	int nb = 0;
	if (a[0] == '~')
	{
		na = 1;
		++a;
	}
	if (b[0] == '~')
	{
		nb = 1;
		++b;
	}
	for (int i = 3; i >= 0; --i)
	{
		if (na)
			negate(a + i);
		if (nb)
			negate(b + i);
		a[i] = (a[i] - '0' && b[i] - '0') + '0';
	}
	return a;
}

int toInt(char* bits)
{
	int result = 0;
	for (int i = 3; i >= 0; --i)
	{
		if (bits[i] - '0')
			result += 1 << (3 - i);
	}
	return result;
}
