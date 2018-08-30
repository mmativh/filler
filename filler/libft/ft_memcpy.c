/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:12:53 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/04 12:02:08 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t num)
{
	size_t	i;
	char	*cfrom;
	char	*cto;

	cfrom = (char *)from;
	cto = (char *)to;
	i = 0;
	while (num > i)
	{
		cto[i] = cfrom[i];
		i++;
	}
	return (to);
}
