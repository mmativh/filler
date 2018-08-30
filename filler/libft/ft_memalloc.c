/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:51:59 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/01 09:41:46 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*allo;

	i = 0;
	if (!(allo = (void *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(allo, size);
	return (allo);
}
