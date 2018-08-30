/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:00:14 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/14 10:03:42 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nbrr(int n)
{
	if (n > 0)
	{
		ft_nbrr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void		ft_putnbr(int n)
{
	int isneg;

	if (n == 0)
		ft_putchar('0');
	isneg = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		isneg = 1;
	}
	if (isneg)
		ft_putchar('-');
	ft_nbrr(n);
}
