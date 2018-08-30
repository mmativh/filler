/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:58:12 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/05 09:05:12 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ns;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	if (!(ns = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len > i)
	{
		ns[i] = f(s[i]);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
