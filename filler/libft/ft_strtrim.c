/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:51:43 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/18 09:26:32 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_trims(char *s, size_t *len)
{
	size_t i;

	i = 0;
	while (ft_ifspace(s[i]))
		i++;
	while (ft_ifspace(s[*len - 1]) && (*len > i))
		*len = *len - 1;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*ns;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = ft_trims((char *)s, &len);
	len = len - i;
	if (!(ns = ft_strsub(s, i, len)))
		return (NULL);
	return (ns);
}
