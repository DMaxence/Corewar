/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:16:18 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/10 00:05:46 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	tmp = (char *)s;
	while (tmp[i])
	{
		if (tmp[i] == (char)c)
			j = i;
		i++;
	}
	if (tmp[i] == '\0' && (char)c == '\0')
		return (&tmp[i]);
	if (j == -1)
		return (NULL);
	return (&tmp[j]);
}
