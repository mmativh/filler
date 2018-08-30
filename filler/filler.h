/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 09:17:45 by mmathivh          #+#    #+#             */
/*   Updated: 2018/08/06 15:40:31 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <stdio.h>
# define MPHO 160

typedef	struct	s_dlist
{
	int			py;
	int			px;
	int			mx;
	int			my;
	int			ty;
	int			tx;
	int			ply;
	int			init;
	int			trim[4];
	int			opp[4];
	int			cord[4];
	int			count;
	int			small;
	int			cn;
	char		pc;
	char		op;
	char		**map;
	char		**token;
	int			play;
	int			**hmap;

}				t_lst;

int				ft_inbounds(int x, int y, t_lst dim);
int				ft_xmin(char **token, int lst);
int				ft_xmax(char **token, int lst);
int				ft_ymin(char **token);
int				ft_ymax(char **token, int lst);
int				*ft_hcol(t_lst *dim);
int				ft_hmap(t_lst *dim);
void			ft_map(int fd, t_lst *dim);
void			ft_pcord(t_lst dim);
void			ft_piece(int fd, t_lst	*dim);
void			ft_genplayer(int fd, t_lst	*dim);
void			ft_trim(t_lst *dim);
void			ft_play_small(int x, int y, t_lst *dim);
void			ft_p(int x, int y, t_lst *dim);
#endif
