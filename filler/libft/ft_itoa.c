/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:13:14 by mmathivh          #+#    #+#             */
/*   Updated: 2018/05/31 13:51:23 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ilen(int n)
{
	int	temp;
	int	len;

	temp = n;
	len = 2;
	while (temp > 9)
	{
		len++;
		temp = temp / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		isneg;
	int		len;
	char	*str;

	isneg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		isneg = 1;
	}
	len = ft_ilen(n) + isneg;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (isneg)
		str[0] = '-';
	return (str);
}
