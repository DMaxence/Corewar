/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:52:17 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/10 16:52:18 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	res = NULL;
	if (s1 && s2)
	{
		if (!(res = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2))))
			return (NULL);
		ft_strcpy(res, (char *)s1);
		ft_strcat(res, s2);
	}
	return (res);
}
