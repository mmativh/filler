/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:20:04 by mmathivh          #+#    #+#             */
/*   Updated: 2018/08/14 15:29:17 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **node, t_list *newnode)
{
	if (*node || newnode)
	{
		newnode->next = *node;
		*node = newnode;
	}
	return ;
}
