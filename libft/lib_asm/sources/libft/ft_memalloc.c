/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:54:00 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/23 12:14:32 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone;
	size_t	i;

	i = 0;
	if (!(zone = (unsigned char *)malloc(sizeof(*zone) * size)))
		return (NULL);
	while (i < size)
	{
		((unsigned char *)zone)[i] = '\0';
		i++;
	}
	return (zone);
}
