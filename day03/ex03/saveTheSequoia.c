/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:34:37 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/28 11:20:25 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap(struct s_node** parent, struct s_node** child)
{
	struct s_node* tmp = *parent;
	struct s_node* child_left = (*child)->left;
	struct s_node* child_right = (*child)->right;
	*parent = *child;
	if (tmp->left == *child)
	{
		(*child)->right = tmp->right;
		(*child)->left = tmp;
	}
	else
	{
		(*child)->left = tmp->left;
		(*child)->right = tmp;
	}
	tmp->left = child_left;
	tmp->right = child_right;
}

void maxHeapify(struct s_node** node)
{
	if (!*node)
		return;
	if ((*node)->left && (*node)->value < (*node)->left->value)
		swap(node, &((*node)->left));
	if ((*node)->right && (*node)->value < (*node)->right->value)
		swap(node, &((*node)->right));
	maxHeapify(&((*node)->left));
	maxHeapify(&((*node)->right));
}

static int height(struct s_node* node)
{
    if (!node)
        return 0;
    int left = height(node->left);
    int right = height(node->right);
    if (left > right)
        return left + 1;
    return right + 1;
}

void saveTheSequoia(struct s_node** root)
{
	int h = height(*root);
	for (int i = 0; i < h; ++i)
		maxHeapify(root);
}
