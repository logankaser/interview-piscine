/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:19:01 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/26 20:45:01 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "header.h"

static void elementInfo(struct s_info* info, struct s_node* node)
{
	if (!node)
		return;
	info->elements += 1;
	if (node->value > info->max)
		info->max = node->value;
	if (node->value < info->min)
		info->min = node->value;
	elementInfo(info, node->left);
	elementInfo(info, node->right);
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

static int heightTree(struct s_node* root)
{
	if (!(root->left || root->right))
		return 0;
	return height(root) - 1;
}

static int isBST(struct s_node* node)
{
	if (!node)
		return 1;
	if (node->left && node->left->value > node->value)
		return 0;
	if (node->right && node->right->value < node->value)
		return 0;
	if (!isBST(node->left) || !isBST(node->right))
		return 0;
	return 1;
}

static int isBalanced(struct s_node* node)
{
	if (!node)
		return 0;
	int left = isBalanced(node->left);
	int right = isBalanced(node->right);
	if (left == -1 || right == -1)
		return -1;
	if (left > right + 1 || right > left + 1)
		return -1;
	if (left > right)
		return left + 1;
	return right + 1;
}

struct s_info getInfo(struct s_node* root)
{
	struct s_info info = {0,0,0,0,0,0};
	elementInfo(&info, root);
	info.height = heightTree(root);
	info.isBST = isBST(root);
	info.isBalanced = isBalanced(root) != -1;
	return info;
}
