/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:17:39 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/14 10:24:00 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len;

	len = ft_strlen(dst);
	if (ft_strlen(dst) > dstsize)
		return (dstsize + ft_strlen(src));
	else if (len < dstsize)
		ft_strncat(dst, src, dstsize - ft_strlen(dst) - 1);
	return (ft_strlen(src) + len);
}
