/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:01:38 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/29 09:18:29 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **node, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!*node || !del)
		return ;
	while (*node)
	{
		temp = (*node)->next;
		del((*node)->content, (*node)->content_size);
		free(*node);
		*node = temp;
	}
	*node = NULL;
}
