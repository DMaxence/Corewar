/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:32:38 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/26 18:35:06 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_tabdel(char ***tab)
{
	int		i;
	int		len;

	i = 0;
	if (tab)
	{
		len = ft_tablen(*tab);
		while (i < len)
		{
			ft_strdel(&(*tab)[i]);
			i++;
		}
		free(*tab);
		*tab = NULL;
	}
}
