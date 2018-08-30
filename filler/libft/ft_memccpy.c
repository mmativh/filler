/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:30:26 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/13 15:20:33 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *to, const void *from, int c, size_t num)
{
	size_t			i;
	unsigned char	p;
	unsigned char	*cfrom;
	unsigned char	*cto;

	p = (unsigned char)c;
	cfrom = (unsigned char *)from;
	cto = (unsigned char *)to;
	i = 0;
	while (num > i)
	{
		cto[i] = cfrom[i];
		if (cfrom[i] == p)
		{
			return (cto + i + 1);
		}
		i++;
	}
	return (NULL);
}
