/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:51:11 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/10 16:51:13 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*cpy;
	char	*res;

	i = 0;
	cpy = (char *)s;
	res = NULL;
	if (s)
	{
		if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(cpy) + 1))))
			return (NULL);
		while (cpy[i])
		{
			res[i] = f(i, cpy[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
