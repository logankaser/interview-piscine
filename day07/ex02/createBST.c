/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 12:51:43 by lkaser            #+#    #+#             */
/*   Updated: 2018/05/04 21:24:14 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

struct s_node* newNode(int value)
{
	struct s_node* new = calloc(1, sizeof(struct s_node));
	new->value = value;
	return new;
}

struct s_node* buildBST(int array[], int lo, int hi)
{
	if (lo > hi)
		return NULL;
	int mid = (lo + hi) / 2;
	struct s_node* node = newNode(array[mid]);
	node->left = buildBST(array, lo, mid - 1);
	node->right = buildBST(array, mid + 1, hi);
	return node;
}

struct s_node* createBST(int* array, int n)
{
	return buildBST(array, 0, n - 1);
}
