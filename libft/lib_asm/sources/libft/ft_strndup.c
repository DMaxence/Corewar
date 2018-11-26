/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:26:17 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/21 14:26:21 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int nb)
{
	char	*dest;
	int		size;
	int		i;

	size = 0;
	while (src[size] && size < nb)
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
