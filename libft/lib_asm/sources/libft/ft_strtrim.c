/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:53:11 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/10 16:53:12 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;
	char		*res;

	res = NULL;
	if (s)
	{
		start = 0;
		end = ft_strlen(s);
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
			end--;
		if (start > end)
			end = start;
		if (!(res = ft_strnew((end - start))))
			return (NULL);
		res = ft_strncpy(res, ((char *)s + start), (end - start));
	}
	return (res);
}
