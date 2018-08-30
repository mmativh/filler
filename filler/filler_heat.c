/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_heat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 10:24:21 by mmathivh          #+#    #+#             */
/*   Updated: 2018/08/06 15:37:50 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	*ft_hcol(t_lst *dim)
{
	int	*col;
	int	i;

	i = 0;
	col = (int *)malloc(sizeof(int) * dim->mx);
	while (i < dim->mx)
	{
		col[i] = 0;
		i++;
	}
	return (col);
}

int	ft_mapedit_y(int x, int y, t_lst *dim)
{
	char	**map;
	int		**hmap;

	map = dim->map;
	hmap = dim->hmap;
	if (y - 1 >= 0)
	{
		if (map[y - 1][x] == dim->op && dim->init == 0)
			hmap[y][x] = MPHO;
		if (hmap[y][x] != MPHO && hmap[y - 1][x] > 0)
		{
			if (hmap[y][x] < hmap[y - 1][x] - 1)
				hmap[y][x] = hmap[y - 1][x] - 1;
		}
	}
	if (y + 1 < dim->my)
	{
		if (map[y + 1][x] == dim->op && dim->init == 0)
			hmap[y][x] = MPHO;
		if (hmap[y][x] != MPHO && hmap[y + 1][x] > 0)
		{
			if (hmap[y][x] < hmap[y + 1][x] - 1)
				hmap[y][x] = hmap[y + 1][x] - 1;
		}
	}
	return (1);
}

int	ft_mapedit_x(int x, int y, t_lst *dim)
{
	char	**map;
	int		**hmap;

	map = dim->map;
	hmap = dim->hmap;
	if (x - 1 >= 0)
	{
		if (map[y][x - 1] == dim->op && dim->init == 0)
			hmap[y][x] = MPHO;
		if (hmap[y][x] != MPHO && hmap[y][x - 1] > 0)
		{
			if (hmap[y][x] < hmap[y][x - 1] - 1)
				hmap[y][x] = hmap[y][x - 1] - 1;
		}
	}
	if (x + 1 < dim->mx)
	{
		if (map[y][x + 1] == dim->op && dim->init == 0)
			hmap[y][x] = MPHO;
		if (hmap[y][x] != MPHO && hmap[y][x + 1] > 0)
		{	
			if (hmap[y][x] < hmap[y][x + 1] - 1)
				hmap[y][x] = hmap[y][x + 1] - 1;
		}
	}
	return (1);
}

int	ft_hmap(t_lst *dim)
{
	int		x;
	int		y;
	char	**map;

	map = dim->map;
	x = 0;
	y = 0;
	if (dim->count == 49)
		return (0);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_mapedit_y(x, y, dim);
			ft_mapedit_x(x, y, dim);
			x++;
		}
		y++;
	}
	dim->init = 1;
	dim->count = dim->count + 1;
	return (1);
}
