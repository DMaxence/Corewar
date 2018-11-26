/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:05:16 by bvigne            #+#    #+#             */
/*   Updated: 2018/02/21 18:09:43 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_num_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '-' || (str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'a' && str[i] <= 'f')))
			return (1);
		i++;
	}
	return (0);
}

int		ft_atobase(char *str, char *base)
{
	int		dec;
	int		i;
	int		y;
	int		j;

	j = 0;
	dec = 0;
	if (check_num_str(str))
		return (0);
	i = ft_strlen(str) - 1;
	while (str[i] && str[i] != '-' && str[i] != '+' && i >= 0)
	{
		y = 0;
		while (base[y] && str[i] != base[y])
			y++;
		if (y == (int)ft_strlen(base))
			y = 0;
		dec += y * ft_power(ft_strlen(base), j++);
		i--;
	}
	return (str[0] == '-' ? dec * -1 : dec);
}
