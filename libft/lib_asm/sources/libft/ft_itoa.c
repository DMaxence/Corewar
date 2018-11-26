/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:53:37 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/15 15:42:52 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_n(int cpy)
{
	int		taille;

	taille = 0;
	if (cpy == 0)
		return (1);
	while (cpy)
	{
		cpy = cpy / 10;
		taille++;
	}
	return (taille);
}

static char	*file_res(int i, char *res, int taille, int n)
{
	if (i)
	{
		res[0] = 45;
		taille--;
	}
	while (taille)
	{
		res[i] = n / ft_power(10, (taille - 1)) + 48;
		n = n % ft_power(10, (taille - 1));
		taille--;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		taille;
	int		i;

	res = NULL;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	taille = len_n(n) + i;
	if (!(res = (char*)malloc(sizeof(char) * (taille + 1))))
		return (NULL);
	res = file_res(i, res, taille, n);
	return (res);
}
