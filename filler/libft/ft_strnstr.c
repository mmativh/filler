/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:00:56 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/14 07:32:39 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t len2;

	i = 0;
	len2 = ft_strlen(needle);
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len2 <= len)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_memcmp(haystack + i, needle, len2) == 0)
				return ((char *)haystack + i);
		}
		i++;
		len--;
	}
	return (NULL);
}
