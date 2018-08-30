/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:50:01 by mmathivh          #+#    #+#             */
/*   Updated: 2018/08/03 13:06:11 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int	ft_inbounds(int x, int y, t_lst dim)
{
	if (((y + dim.ty - (dim.trim[2] + dim.trim[3])) > dim.my) ||
			(x + dim.tx - (dim.trim[0] + dim.trim[1]) > dim.mx))
		return (0);
	return (1);
}

int	ft_xmin(char **token, int lst)
{
	int		i;
	int		j;
	int		c;
	int		min;

	i = 0;
	min = lst;
	while (token[i])
	{
		j = 0;
		c = 0;
		while (token[i][j] != '\0' && token[i][j] == '.')
		{
			c++;
			j++;
		}
		if (c < min)
			min = c;
		i++;
	}
	return (min);
}

int	ft_xmax(char **token, int lst)
{
	int	i;
	int	j;
	int	c;
	int	max;

	max = lst - 1;
	i = 0;
	while (token[i])
	{
		j = lst - 1;
		c = 0;
		while (j > 0 && token[i][j] == '.')
		{
			c++;
			j--;
		}
		if (c < max)
			max = c;
		i++;
	}
	return (max);
}

int	ft_ymin(char **token)
{
	int	i;
	int	j;

	i = 0;
	while (token[i])
	{
		j = 0;
		while (token[i][j])
		{
			if (token[i][j] == '*')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_ymax(char **token, int lst)
{
	int	j;
	int	i;
	int	c;

	i = lst - 1;
	c = 0;
	while (i >= 0)
	{
		j = 0;
		while (token[i][j])
		{
			if (token[i][j] == '*')
				return (c);
			j++;
		}
		c++;
		i--;
	}
	return (0);
}
