/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:02:59 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/29 09:16:44 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **node, void (*del)(void*, size_t))
{
	del((*node)->content, (*node)->content_size);
	free(*node);
	*node = (void*)0;
}
