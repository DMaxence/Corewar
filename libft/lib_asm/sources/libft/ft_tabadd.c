/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:32:38 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/26 19:00:16 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_tabcpy_plus(char **src, int len)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = NULL;
	if (!(cpy = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (i < len - 1)
	{
		cpy[i] = ft_strdup(src[i]);
		i++;
	}
	cpy[i] = NULL;
	cpy[i + 1] = NULL;
	return (cpy);
}

char			**ft_tabadd(char **src, char *add)
{
	char	**ret;

	ret = NULL;
	if (src != NULL)
	{
		ret = ft_tabcpy_plus(src, ft_tablen(src) + 1);
		ret[ft_tablen(src)] = ft_strdup(add);
		ft_strdel(&add);
		ret[ft_tablen(src) + 1] = NULL;
		ft_tabdel(&src);
	}
	else
	{
		if (!(ret = (char **)malloc(sizeof(char *) * 2)))
			return (NULL);
		ret[0] = ft_strdup(add);
		ft_strdel(&add);
		ret[1] = NULL;
	}
	return (ret);
}
