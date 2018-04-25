/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:35:34 by lkaser            #+#    #+#             */
/*   Updated: 2018/04/24 13:44:19 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "header.h"

void reversePut(struct s_node *lst)
{
	if (lst->next)
	{
		reversePut(lst->next);
		write(1, " ", 1);
	}
	write(1, lst->word, strlen(lst->word));
}

void printReverse(struct s_node *lst)
{
	reversePut(lst);
	write(1, "\n", 1);
}
