/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:53:23 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/20 20:09:24 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nblet(char *cpy, char c)
{
	int		i;

	i = 0;
	while (cpy[i] != c && cpy[i])
		i++;
	return (i);
}

static int		nbch(char *cpy, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (cpy[i])
	{
		if (cpy[i] == c && (cpy[i - 1] != c || i == 0) && cpy[i + 1])
			len++;
		i++;
	}
	return (len);
}

static char		*fill(char *cpy, int start, int len)
{
	char	*res;

	res = NULL;
	res = ft_strsub(cpy, start, len);
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	int		start;
	int		i;
	char	**tab;

	start = 0;
	i = 0;
	tab = NULL;
	if (s)
	{
		if (!(tab = (char **)malloc(sizeof(char *) * (nbch((char *)s, c) + 2))))
			return (NULL);
		while (s[start])
		{
			if (s[start] == c)
				start++;
			else if (s[start] != c)
			{
				tab[i] = fill((char *)s, start, nblet(((char *)s + start), c));
				i++;
				start = start + nblet(((char *)s + start), c);
			}
		}
		tab[i] = NULL;
	}
	return (tab);
}
