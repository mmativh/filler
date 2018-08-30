/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:12:20 by mmathivh          #+#    #+#             */
/*   Updated: 2018/08/07 08:13:21 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*free_strjoin(char **str, char *s, int fd)
{
	size_t	i;
	size_t	j;
	char	*new_s;
	char	*temp;

	if (str == NULL || s == NULL)
		return (NULL);
	if (!(new_s = ft_strnew(ft_strlen(str[fd]) + ft_strlen(s))))
		return (NULL);
	i = -1;
	while (str[fd][++i])
		new_s[i] = str[fd][i];
	j = 0;
	while (s[j])
		new_s[i++] = s[j++];
	temp = str[fd];
	free(str[fd]);
	str[fd] = temp;
	return (new_s);
}

static	int		get_newline(char **str, char **line, int fd)
{
	int		pos;
	char	*temp;

	pos = 0;
	while (str[fd][pos])
	{
		if (str[fd][pos] == '\n')
			break ;
		pos++;
	}
	if (str[fd][pos] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	else
	{
		*line = ft_strsub(str[fd], 0, pos);
		temp = ft_strsub(str[fd], pos + 1, ft_strlen(str[fd]));
		free(str[fd]);
		str[fd] = temp;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[1];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		str[fd] = free_strjoin(str, buf, fd);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	get_newline(str, line, fd);
	return (1);
}
