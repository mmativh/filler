/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:56:46 by mmathivh          #+#    #+#             */
/*   Updated: 2018/05/31 08:18:03 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*newc;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	if (!(newc = (char *)malloc(sizeof(char) * len)))
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		newc[i] = s1[i];
		i++;
	}
	newc[i] = '\0';
	return (newc);
}
