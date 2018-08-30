/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_play.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 10:24:21 by mmathivh          #+#    #+#             */
/*   Updated: 2018/08/06 15:48:10 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_pcord(t_lst dim)
{
	ft_putnbr(dim.cord[0] - dim.trim[2]);
	ft_putchar(' ');
	ft_putnbr(dim.cord[1] - dim.trim[0]);
	ft_putchar('\n');
}

void	ft_med_map(int x, int y, t_lst *dim)
{
//	if (x <= 3)
		dim->small = 0;
	if (dim->cord[1] > x)
	{
		dim->cord[0] = y;
		dim->cord[1] = x;
		dim->cord[2] = dim->hmap[y][x];
	}
}

void	ft_small_map(int x, int y, t_lst *dim)
{
	if (y <= 7)
	{
		if (dim->cord[0] >= y && dim->cord[1] >= x)
		{
			dim->cord[0] = y;
			dim->cord[1] = x;
			dim->cord[2] = dim->hmap[y][x];
		}
		if (y <= 5)
			dim->small = 0;
	}
	else if (dim->cord[0] >= y)
	{
		dim->cord[0] = y;
		dim->cord[1] = x;
		dim->cord[2] = dim->hmap[y][x];
	}
}

void	ft_play_small(int x, int y, t_lst *dim)
{
	if (dim->my != 24)
		ft_small_map(x, y, dim);
	else
		ft_med_map(x, y, dim);
}

void	ft_p(int x, int y, t_lst *dim)
{
	if (dim->cord[2] < dim->hmap[y][x])
	{
		dim->cord[0] = y;
		dim->cord[1] = x;
		dim->cord[2] = dim->hmap[y][x];
	}
}
