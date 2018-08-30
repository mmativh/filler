/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:04:53 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/29 09:16:58 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *node, void (*f)(t_list *elem))
{
	if (node || f)
	{
		while (node)
		{
			f(node);
			node = node->next;
		}
	}
	return ;
}
