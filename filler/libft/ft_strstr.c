/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:00:56 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/14 07:27:55 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(needle);
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && needle[0] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (ft_memcmp(haystack + i, needle, len) == 0)
			{
				return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
