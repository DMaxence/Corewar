/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:07:19 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/21 16:18:40 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *src, char c)
{
	char	*dest;
	int		size;
	int		i;

	size = 0;
	while (src[size] && src[size] != c)
		size++;
	if (!(dest = (char *)malloc(sizeof(*src) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && (dest[i] || src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
