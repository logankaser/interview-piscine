/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:27:00 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/27 16:49:53 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "header.h"

static int findChildren(struct s_node* node, char* a, char* b)
{
	if (!node)
		return 0;
	int found = 0;
	for (int i = 0; node->children[i]; ++i)
	{
		if (strcmp(node->children[i]->name, a) == 0)
			found += 1;
		else if (strcmp(node->children[i]->name, b) == 0)
			found += 1;
		found += findChildren(node->children[i], a, b);
	}
	return found;
}

struct s_node* findParent(struct s_node* node, char* firstSpecies, char* secondSpecies)
{
	if (!node)
		return NULL;
	for (int i = 0; node->children[i]; ++i)
		if (findChildren(node->children[i], firstSpecies, secondSpecies) == 2)
			return findParent(node->children[i], firstSpecies, secondSpecies);
	if (findChildren(node, firstSpecies, secondSpecies) == 2)
		return node;
	return NULL;
}
