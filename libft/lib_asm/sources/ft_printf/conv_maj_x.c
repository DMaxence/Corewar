/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_maj_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/29 15:15:07 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*modif_larg_with_zero(t_arg *data)
{
	if (data->flag & F_HASH && data->arg[0] != '0')
	{
		if (data->larg > data->size + 2)
			data->arg = pf_x_join(data->larg - data->size - 2, '0', data->size,
			data);
		data->arg = pf_x_join(1, 'X', data->size, data);
		data->arg = pf_x_join(1, '0', data->size, data);
	}
	else
		data->arg = pf_x_join(data->larg - data->size, '0', data->size,
		data);
	return (data->arg);
}

static char		*modif_larg_with_minus(t_arg *data)
{
	if (data->flag & F_HASH && data->arg[0] != '0')
	{
		data->arg = pf_x_join(1, 'X', data->size, data);
		data->arg = pf_x_join(1, '0', data->size, data);
		if (data->larg > data->size)
			data->arg = pf_join_x(data->larg - data->size, ' ', data->size,
			data);
	}
	else
		data->arg = pf_join_x(data->larg - data->size, ' ', data->size,
		data);
	return (data->arg);
}

static char		*modif_preci(int i, t_arg *data)
{
	if (data->preci == 0 && i == 0)
	{
		pf_strdel(&data->arg);
		data->arg = pf_strdup("");
		data->size = 0;
	}
	else if ((!(data->flag & F_ZERO) && data->flag & F_HASH && data->arg[0] !=
	'0' && data->arg[1]) || data->preci > data->size)
	{
		if (data->preci > data->size)
			data->arg = pf_x_join(data->preci - data->size, '0', data->size,
			data);
		if (data->flag & F_HASH && i != 0)
		{
			data->arg = pf_x_join(1, 'X', data->size, data);
			data->arg = pf_x_join(1, '0', data->size, data);
		}
	}
	return (data->arg);
}

static char		*modify_conv(int i, t_arg *data)
{
	data->arg = modif_preci(i, data);
	if (data->larg > data->size && data->flag & F_ZERO)
		data->arg = modif_larg_with_zero(data);
	else if (data->larg > data->size && data->flag & F_MINUS)
		data->arg = modif_larg_with_minus(data);
	else if (data->larg > data->size)
	{
		if (data->flag & F_HASH && data->arg[0] != '0')
		{
			data->arg = pf_x_join(1, 'X', data->size, data);
			data->arg = pf_x_join(1, '0', data->size, data);
		}
		if (data->larg > data->size)
			data->arg = pf_x_join(data->larg - data->size, ' ', data->size,
			data);
	}
	else if (data->flag & F_HASH && data->arg[0] != '0' && data->size != 0)
	{
		data->arg = pf_x_join(1, 'X', data->size, data);
		data->arg = pf_x_join(1, '0', data->size, data);
	}
	return (data->arg);
}

int				conv_maj_x(t_arg *data, va_list ap)
{
	uintmax_t	i;

	i = va_arg(ap, uintmax_t);
	if (data->flag & F_L)
		i = (unsigned long)i;
	else if (data->flag & F_LL)
		i = (unsigned long long)i;
	else if (data->flag & F_H)
		i = (unsigned short int)i;
	else if (data->flag & F_HH)
		i = (unsigned char)i;
	else if (data->flag & F_J)
		i = (uintmax_t)i;
	else if (data->flag & F_Z)
		i = (size_t)i;
	else
		i = (unsigned int)i;
	data->arg = pf_utoa_base(i, 16);
	data->size = pf_strlen(data->arg);
	data->arg = modify_conv(i, data);
	add_to_buf(data);
	data->buf = pf_strjoin(data->buf, data->arg, data);
	return (data->size);
}
