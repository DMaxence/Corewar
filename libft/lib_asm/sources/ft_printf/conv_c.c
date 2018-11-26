/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/31 15:26:29 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*modify_conv(t_arg *data)
{
	if (data->larg > 1)
	{
		if (data->flag & F_MINUS)
			data->arg = pf_join_x(data->larg - 1, ' ', data->size, data);
		else if (data->flag & F_ZERO)
			data->arg = pf_x_join(data->larg - 1, '0', data->size, data);
		else
			data->arg = pf_x_join(data->larg - 1, ' ', data->size, data);
	}
	return (data->arg);
}

static int		get_uni(wchar_t c, t_arg *data)
{
	if (parse_exep(c, NULL, data) == 0)
		return (-1);
	if (c <= 127)
		return (first_uni(c, &data->arg));
	else if (c <= 0x7FF)
		return (second_uni(c, &data->arg, data, 'c'));
	else if (c <= 0xFFFF)
		return (third_uni(c, &data->arg, data, 'c'));
	else if (c <= 0x10FFFF)
		return (fourth_uni(c, &data->arg, data, 'c'));
	pf_strdel(&data->arg);
	return (-1);
}

int				conv_c(t_arg *data, va_list ap)
{
	wchar_t		c;

	c = va_arg(ap, wchar_t);
	if (!(data->flag & F_L) && c != 0)
	{
		data->arg = pf_strnew(2);
		data->arg[0] = c;
		data->arg[1] = '\0';
	}
	else if (c == 0)
		data->arg = pf_strdup("");
	data->size = 1;
	if (data->flag & F_L && c != 0)
	{
		data->arg = pf_strnew(5);
		data->size = get_uni(c, data);
		if (data->size < 0)
			return (-1);
	}
	data->arg = modify_conv(data);
	add_to_buf(data);
	data->buf = pf_strjoin(data->buf, data->arg, data);
	return (data->size);
}

int				conv_none(char let, t_arg *data)
{
	data->arg = pf_strnew(2);
	data->arg[0] = let;
	data->arg[1] = '\0';
	data->size = 1;
	data->arg = modify_conv(data);
	add_to_buf(data);
	data->buf = pf_strjoin(data->buf, data->arg, data);
	data->len += data->size;
	return (1);
}
