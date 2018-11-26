/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:35:32 by tbleuse           #+#    #+#             */
/*   Updated: 2018/07/26 14:10:55 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../header/str.h"

char	*ft_strrstr(const char *haystack, const char *needle)
{
	int				i;
	int				j;
	int				save;

	i = ft_strlen(haystack) - ft_strlen(needle);
	save = 0;
	if (!needle[0])
		return ((char*)haystack);
	while (i >= 0)
	{
		j = -1;
		while (haystack[i] == needle[++j])
		{
			if (!needle[j + 1])
				return ((char*)&haystack[save]);
			++i;
		}
		i = --save;
	}
	return (NULL);
}
