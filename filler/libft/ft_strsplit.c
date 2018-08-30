/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmathivh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 09:50:36 by mmathivh          #+#    #+#             */
/*   Updated: 2018/06/14 10:14:53 by mmathivh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_colnum(char *s, size_t *n, char c)
{
	size_t	f;
	size_t	cc;

	f = 0;
	cc = 0;
	while (s[*n] != '\0' && s[*n] == c)
	{
		*n = *n + 1;
	}
	while (s[*n] != '\0' && s[*n] != c)
	{
		*n = *n + 1;
		cc++;
	}
	*n = *n - cc;
	return (cc);
}

static	char	**ft_fillc(char *s, char **ns, char c, size_t cn)
{
	size_t f;
	size_t nc;
	size_t i;
	size_t n;

	i = 0;
	f = 0;
	n = 0;
	while (i < cn)
	{
		nc = ft_colnum(s, &n, c);
		if (!(ns[i] = (char *)malloc(sizeof(char) * nc + 1)))
			return (0);
		while (s[n] != c && s[n] != '\0')
		{
			ns[i][f] = s[n];
			n++;
			f++;
		}
		ns[i][f] = '\0';
		i++;
		f = 0;
	}
	ns[i] = NULL;
	return (ns);
}

static size_t	ft_rows(char *s, char c)
{
	size_t	i;
	size_t	r;

	i = 0;
	r = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i] != '\0'))
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			r++;
		}
		else
			i++;
	}
	return (r);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	cn;
	char	**ns;

	i = 0;
	if (!s)
		return (NULL);
	cn = ft_rows((char *)s, c);
	if (!(ns = (char **)malloc(sizeof(char *) * cn + 1)))
		return (NULL);
	return (ft_fillc((char *)s, ns, c, cn));
}
