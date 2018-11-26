/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:36:24 by tbleuse           #+#    #+#             */
/*   Updated: 2018/07/26 14:21:36 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strpbrk(const char *s, const char *charset)
{
	int		i;
	int		j;

	j = 0;
	while (charset[j])
	{
		i = 0;
		while (s[i] && s[i] != charset[j])
			++i;
		if (s[i] == charset[j])
			return ((char*)&s[i]);
		++j;
	}
	return (NULL);
}
