/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:50:21 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/10 16:50:24 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnsep(char *str, int n, char c)
{
	char	*s;
	int		pos;
	int		i;

	i = 0;
	pos = 1;
	s = NULL;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == c)
				pos++;
			if (pos == n && str[i] == c && str[i + 1])
			{
				s = ft_strcdup(str + i + 1, c);
				break ;
			}
			i++;
		}
	}
	return (s);
}
