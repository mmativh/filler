/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:50:01 by mmathivh          #+#    #+#             */
/*   Updated: 2018/08/06 15:34:58 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_checkcord(int x, int y, int st_y, t_lst *dim)
{
	int u;
	int r;

	u = dim->trim[0];
	r = x;
	while (st_y < (dim->ty - dim->trim[3]))
	{
		u = dim->trim[0];
		x = r;
		while (u < (dim->tx - dim->trim[1]))
		{
			if ((dim->map[y][x] == dim->pc && dim->token[st_y][u] == '*'))
				dim->cn++;
			if ((dim->map[y][x] == dim->op && dim->token[st_y][u] == '*'))
				return (0);
			x++;
			u++;
		}
		st_y++;
		y++;
	}
	if (dim->cn == 1)
		return (1);
	return (0);
}

void	ft_place(int *place, int x, int y, t_lst *dim)
{
	int i;

	i = 0;
	dim->cn = 0;
	if (ft_inbounds(x, y, (*dim)))
	{
		if (ft_checkcord(x, y, dim->trim[2], dim))
		{
			if (*place == 0)
			{
				dim->cord[0] = y;
				dim->cord[1] = x;
				dim->cord[2] = dim->hmap[y][x];
			}
			while (dim->hmap[i])
			{
				i++;
			}
			*place = 1;
			if (dim->small == 1)
				ft_play_small(x, y, dim);
			else
				ft_p(x, y, dim);
		}
	}
}

int		ft_play(char **map, t_lst *dim)
{
	int x;
	int y;
	int place;

	x = 0;
	y = 0;
	place = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_place(&place, x, y, dim);
			x++;
		}
		y++;
	}
	if (!place)
	{
		ft_putendl("0 0");
		return (0);
	}
	ft_pcord((*dim));
	return (1);
}

int		main(void)
{
	t_lst	dime;
	int		i;
//	int y;
//	int x;

	i = 0;
	ft_genplayer(0, &dime);
	dime.play = 0;
	dime.cord[0] = 0;
	dime.cord[1] = 0;
	dime.cord[2] = 0;
	dime.cord[3] = 0;
	while (1)
	{
//		y = 0;
//		x = 0;
		dime.count = 0;
		dime.init = 0;
		ft_map(0, &dime);
		ft_piece(0, &dime);
		while (ft_hmap(&dime))
			i++;
	/*	while(y < 24)
		{
			x = 0;
			while(x < 40)
			{
				fprintf(stderr, " %i ", dime.hmap[y][x]);
				x++;
			}
			fprintf(stderr, "\n");
			y++;
		} */
		ft_trim(&dime);
		if (!ft_play(dime.map, &dime))
			break ;
	}
	return (0);
}
