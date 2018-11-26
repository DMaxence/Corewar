/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:25:17 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/23 14:58:15 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoinfree(char *s1, char c)
{
	char	*res;

	res = NULL;
	if (s1 && c)
	{
		if (!(res = ft_strnew(ft_strlen((char *)s1) + 2)))
			return (NULL);
		ft_strcpy(res, (char *)s1);
		res[ft_strlen((char *)s1)] = c;
		res[ft_strlen((char *)s1) + 1] = '\0';
		ft_strdel(&s1);
	}
	return (res);
}
