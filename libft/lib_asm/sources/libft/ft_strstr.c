/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:16:18 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/22 13:14:31 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		test_str(char *src, char const *to_find, int l)
{
	int		i;

	i = 0;
	while (i < l)
	{
		if (to_find[i] != src[i])
			return (0);
		i++;
	}
	return (1);
}

char			*ft_strstr(const char *to_look, const char *to_find)
{
	int		i;
	int		l;
	char	*str;

	i = 0;
	l = 0;
	str = (char *)to_look;
	while (to_find[l])
		l++;
	if (l == 0)
		return (str);
	while (str[i])
	{
		if (test_str(str + i, to_find, l))
			return (str + i);
		i++;
	}
	return (NULL);
}
