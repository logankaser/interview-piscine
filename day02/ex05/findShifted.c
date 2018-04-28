/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:07:22 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/26 15:14:17 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

static int search(int array[], int l, int h, int val)
{
	int low = l;
	int high = h;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (array[mid] == val)
            return mid;
        else if (array[mid] > val)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

static int findShift(int array[], int n)
{
	for (int i = 0; i < n - 1; ++i)
		if (array[i] > array[i + 1])
			return i;
	return n;
}

int	searchShifted(int rocks[], int length, int value)
{
	int shift = findShift(rocks, length);
	int a = search(rocks, 0, shift, value);
	printf("%i\n", shift);
	printf("search 1\n");
	if (a != -1)
		return a;
	printf("search 2\n");
	int b = search(rocks, shift + 1, length, value);
	if (b != -1)
		return b;
	return -1;
}
