/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:51:52 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/10 16:51:54 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*cpy;
	char		*tron;
	size_t		i;

	i = 0;
	cpy = (char *)s;
	tron = NULL;
	if (s)
	{
		if (!(tron = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			tron[i] = cpy[start];
			start++;
			i++;
		}
		tron[i] = '\0';
	}
	return (tron);
}
