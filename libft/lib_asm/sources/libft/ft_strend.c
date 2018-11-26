/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:23:01 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/26 11:29:09 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strend(char *str, char *end)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i + 1])
		i++;
	while (end[j] && end[j + 1])
		j++;
	if (j > i)
		return (0);
	while (j >= 0)
	{
		if (str[i] == end[j])
		{
			j--;
			i--;
		}
		else
			return (0);
	}
	return (1);
}
