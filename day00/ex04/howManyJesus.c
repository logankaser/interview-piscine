/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:32:07 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/24 09:07:29 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "header.h"

// Must be less than 3 bytes.
#define PRIME 101

int	howManyJesus(char* text, char* pattern)
{
	int M = strlen(pattern);
	int N = strlen(text);
	int p = 0; // pattern hash
	int t = 0; // text hash
	int h = 1;
	size_t total = 0;

	for (int i = 0; i < M - 1; ++i)
		h = (h * 256) % PRIME;

	for (int i = 0; i < M; ++i)
	{
		p = (256 * p + pattern[i]) % PRIME;
		t = (256 * t + text[i]) % PRIME;
	}
	for (int i = 0; i <= N - M; ++i)
	{
		if (p == t && strncmp(text + i, pattern, M) == 0)
			++total;
		if (i < N - M)
		{
			t = (256 * (t - text[i] * h) + text[i + M]) % PRIME;
			if (t < 0)
				t = t + PRIME;
		}
	}
	return total;
}
