/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:16:18 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/22 13:20:43 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test_strn(char *src, char const *to_find, int l, int len)
{
	int		i;

	i = 0;
	while (i < l)
	{
		if (to_find[i] != src[i] || i == len)
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strnstr(const char *to_look, const char *to_find, size_t len)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(to_find);
	str = (char *)to_look;
	while (i < (int)len && str[i])
	{
		if (test_strn(str + i, to_find, j, (int)len - i))
			return (str + i);
		i++;
	}
	return (NULL);
}
