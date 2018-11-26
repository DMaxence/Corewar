/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unicode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/31 15:29:57 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		first_uni(int c, char **uni)
{
	(*uni)[0] = c;
	return (1);
}

int		second_uni(int c, char **uni, t_arg *data, char conv)
{
	(*uni)[0] = (c >> 6) | 0xC0;
	(*uni)[1] = (c & 0x3F) | 0x80;
	if (data->larg && conv != 'C' && conv != 'S' && conv != 's')
		data->larg -= 1;
	else if (data->larg < 2 && conv != 'c' && conv != 's')
		data->larg = 2;
	return (2);
}

int		third_uni(int c, char **uni, t_arg *data, char conv)
{
	(*uni)[0] = (c >> 12) | 0xE0;
	(*uni)[1] = ((c >> 6) & 0x3F) | 0x80;
	(*uni)[2] = (c & 0x3F) | 0x80;
	if (data->larg && conv != 'C' && conv != 'S' && conv != 's')
		data->larg -= 2;
	else if (data->larg < 3 && conv != 'c' && conv != 's')
		data->larg = 3;
	return (3);
}

int		fourth_uni(int c, char **uni, t_arg *data, char conv)
{
	(*uni)[0] = (c >> 18) | 0xF0;
	(*uni)[1] = ((c >> 12) & 0x3F) | 0x80;
	(*uni)[2] = ((c >> 6) & 0x3F) | 0x80;
	(*uni)[3] = (c & 0x3F) | 0x80;
	if (data->larg && conv != 'C' && conv != 'S' && conv != 's')
		data->larg -= 3;
	else if (data->larg < 4 && conv != 'c' && conv != 's')
		data->larg = 4;
	return (4);
}

int		parse_exep(wchar_t c, char **res, t_arg *data)
{
	if (c < 0 || c > 0x10FFFF || (c >= 0xD800 && c <= 0xDFFF) ||
	(c > 0xD7FF && c < 0xE000) || c == 256 || c == 0xbffe)
	{
		if (res != NULL)
			pf_strdel(res);
		pf_strdel(&data->arg);
		return (0);
	}
	return (1);
}
