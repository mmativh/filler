/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:45:28 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/06 14:16:01 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newc;
	size_t	i;

	i = 0;
	if (!(newc = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size >= i)
	{
		newc[i] = '\0';
		i++;
	}
	return (newc);
}
