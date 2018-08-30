/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 10:25:40 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/14 10:57:00 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_max(int n, int fd)
{
	char	*sd;
	int		i;

	i = 0;
	sd = "-2147483648";
	if (n == -2147483648)
	{
		while (sd[i] != '\0')
		{
			ft_putchar_fd(sd[i], fd);
			i++;
		}
		return (1);
	}
	return (0);
}

static void	ft_nbrr(int n, int fd)
{
	if (n > 0)
	{
		ft_nbrr(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int		isneg;

	if (n == 0)
		ft_putchar_fd('0', fd);
	isneg = 0;
	if (ft_max(n, fd) == 1)
		return ;
	if (n < 0)
	{
		n = n * -1;
		isneg = 1;
	}
	if (isneg)
		ft_putchar_fd('-', fd);
	ft_nbrr(n, fd);
}
