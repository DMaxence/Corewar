/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:16:18 by bvigne            #+#    #+#             */
/*   Updated: 2017/07/10 00:05:46 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;
	unsigned char	find;
	size_t			i;

	tmp = (unsigned char *)src;
	tmp2 = (unsigned char *)dest;
	find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		tmp2[i] = tmp[i];
		if (tmp[i] == find)
			return (&tmp2[i + 1]);
		i++;
	}
	return (NULL);
}
