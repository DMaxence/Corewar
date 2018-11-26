/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:51:00 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/17 16:24:58 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			res[i] = f(cpy[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
