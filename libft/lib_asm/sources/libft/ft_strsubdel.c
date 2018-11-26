/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:41:10 by bvigne            #+#    #+#             */
/*   Updated: 2018/02/28 14:43:27 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubdel(char *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (!(tmp = (char *)ft_strnew(len)))
		return (0);
	while (s[start] && i < len && tmp != NULL)
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	free(s);
	return (tmp);
}
