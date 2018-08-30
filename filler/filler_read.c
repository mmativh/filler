/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:50:01 by mmathivh          #+#    #+#             */
/*   Updated: 2018/08/06 07:43:00 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_trim(t_lst *dim)
{
	dim->trim[0] = ft_xmin(dim->token, dim->tx);
	dim->trim[1] = ft_xmax(dim->token, dim->tx);
	dim->trim[2] = ft_ymin(dim->token);
	dim->trim[3] = ft_ymax(dim->token, dim->ty);
}

void	ft_genplayer(int fd, t_lst *dime)
{
	char	*line;

	get_next_line(fd, &line);
	if (line[10] == '1')
	{
		dime->ply = 0;
		dime->pc = 'O';
		dime->op = 'X';
	}
	else
	{
		dime->ply = 1;
		dime->pc = 'X';
		dime->op = 'O';
	}
}

void	ft_map(int fd, t_lst *dime)
{
	int		i;
	char	*line;
	char	**gen;
	int		**hmap;

	i = 0;
	get_next_line(fd, &line);
	dime->my = ft_atoi(ft_strchr(line, ' '));
	dime->mx = ft_atoi(ft_strrchr(line, ' '));
	if (dime->my <= 24)
		dime->small = 1;
	get_next_line(fd, &line);
	gen = (char **)malloc(sizeof(char *) * dime->my + 1);
	hmap = (int **)malloc(sizeof(int *) * dime->my);
	while (i < dime->my)
	{
		get_next_line(fd, &line);
		gen[i] = ft_strdup(line + 4);
		hmap[i] = ft_hcol(dime);
		i++;
		ft_strdel(&line);
	}
	gen[dime->my] = NULL;
	dime->map = gen;
	dime->hmap = hmap;
}

void	ft_piece(int fd, t_lst *dime)
{
	int		i;
	char	*line;
	char	**token;

	get_next_line(fd, &line);
	dime->ty = ft_atoi(ft_strchr(line, ' '));
	dime->tx = ft_atoi(ft_strrchr(line, ' '));
	i = 0;
	token = (char **)malloc(sizeof(char *) * dime->ty + 1);
	while (i < dime->ty)
	{
		get_next_line(fd, &line);
		token[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	token[dime->ty] = NULL;
	dime->token = token;
}
