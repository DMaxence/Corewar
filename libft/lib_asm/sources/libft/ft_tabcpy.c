/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:32:38 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/26 19:00:16 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabcpy(char **src)
{
	int		i;
	int		len;
	char	**cpy;

	i = 0;
	cpy = NULL;
	if (src)
	{
		len = ft_tablen(src);
		if (!(cpy = (char **)malloc(sizeof(char *) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			cpy[i] = ft_strdup(src[i]);
			i++;
		}
		cpy[i] = NULL;
	}
	return (cpy);
}
