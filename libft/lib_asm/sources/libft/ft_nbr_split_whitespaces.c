/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_split_whitespaces.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:11:28 by bvigne            #+#    #+#             */
/*   Updated: 2018/02/06 12:12:23 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbmot(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (((str[i] < '\t' || str[i] > '\v') && str[i] != ' ') && (i == 0
		|| (str[i - 1] >= '\t' && str[i - 1] <= '\v') || str[i - 1] == ' '))
			len += 1;
		i++;
	}
	return (len);
}

int		*ft_nbr_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		*tab;

	i = 0;
	j = 0;
	tab = (int *)malloc(sizeof(int ) * ft_nbmot(str) + 1);
	if (tab == NULL)
		return (0);
	while (str[i])
	{
		if (((str[i] < '\t' || str[i] > '\v') && str[i] != ' ') && (i == 0
		|| (str[i - 1] >= '\t' && str[i - 1] <= '\v') || str[i - 1] == ' '))
		{
			tab[j] = ft_atoi(str + i);
			i = i + ft_nbrlen(tab[j]);
			j++;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
