/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:05:47 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/29 09:15:34 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *node, t_list *(*f)(t_list *elem))
{
	t_list *cnode;
	t_list *hnode;

	if (!(cnode = f(node)))
	{
		free(cnode);
		return (NULL);
	}
	hnode = cnode;
	while (node->next)
	{
		node = node->next;
		if (!(cnode->next = f(node)))
		{
			free(cnode->next);
			return (NULL);
		}
		cnode = cnode->next;
	}
	cnode->next = NULL;
	return (hnode);
}
