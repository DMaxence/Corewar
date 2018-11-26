/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/30 18:02:45 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*modif_larg_i_neg(t_arg *data)
{
	if (data->flag & F_MINUS)
	{
		data->arg = pf_x_join(1, '-', data->size, data);
		data->arg = pf_join_x(data->larg - data->size, ' ', data->size, data);
	}
	else if (data->flag & F_ZERO)
	{
		data->arg = pf_x_join(data->larg - data->size - 1, '0', data->size,
		data);
		data->arg = pf_x_join(1, '-', data->size, data);
	}
	else
	{
		data->arg = pf_x_join(1, '-', data->size, data);
		data->arg = pf_x_join(data->larg - data->size, ' ', data->size, data);
	}
	return (data->arg);
}

static char		*modif_larg_i_pos(t_arg *data)
{
	if (data->flag & F_PLUS)
		data->arg = pf_x_join(1, '+', data->size, data);
	else if (data->flag & F_SPACE)
		data->arg = pf_x_join(1, ' ', data->size, data);
	data->arg = pf_x_join(data->larg - data->size, ' ', data->size, data);
	return (data->arg);
}

static char		*modif_larg_i_pos_with_zemin(t_arg *data)
{
	if (data->flag & F_ZERO && (data->flag & F_PLUS || data->flag & F_SPACE))
	{
		data->arg = pf_x_join(data->larg - data->size - 1, '0', data->size,
		data);
		if (data->flag & F_PLUS)
			data->arg = pf_x_join(1, '+', data->size, data);
		if (data->flag & F_SPACE)
			data->arg = pf_x_join(1, ' ', data->size, data);
	}
	else if (data->flag & F_ZERO && !(data->flag & F_PLUS) &&
	!(data->flag & F_SPACE))
		data->arg = pf_x_join(data->larg - data->size, '0', data->size, data);
	if (data->flag & F_MINUS && (data->flag & F_PLUS || data->flag & F_SPACE))
	{
		data->arg = pf_join_x(data->larg - data->size - 1, ' ', data->size,
		data);
		if (data->flag & F_PLUS)
			data->arg = pf_x_join(1, '+', data->size, data);
		if (data->flag & F_SPACE)
			data->arg = pf_x_join(1, ' ', data->size, data);
	}
	else if (data->flag & F_MINUS && !(data->flag & F_PLUS) &&
	!(data->flag & F_SPACE))
		data->arg = pf_join_x(data->larg - data->size, ' ', data->size, data);
	return (data->arg);
}

static char		*modify_conv(intmax_t i, t_arg *data)
{
	if (data->preci == 0 && i == 0)
	{
		pf_strdel(&data->arg);
		data->arg = pf_strdup("");
		data->size = 0;
	}
	if (data->preci > data->size)
		data->arg = pf_x_join(data->preci - data->size, '0', data->size, data);
	if (data->larg > data->size && i < 0)
		data->arg = modif_larg_i_neg(data);
	else if (data->larg > data->size && i >= 0 && (data->flag & F_ZERO ||
	data->flag & F_MINUS))
		data->arg = modif_larg_i_pos_with_zemin(data);
	else if (data->larg > data->size && i >= 0 && !(data->flag & F_ZERO) &&
	!(data->flag & F_MINUS))
		data->arg = modif_larg_i_pos(data);
	else if (i < 0)
		data->arg = pf_x_join(1, '-', data->size, data);
	else if (data->flag & F_PLUS)
		data->arg = pf_x_join(1, '+', data->size, data);
	else if (data->flag & F_SPACE)
		data->arg = pf_x_join(1, ' ', data->size, data);
	return (data->arg);
}

int				conv_i(t_arg *data, va_list ap)
{
	intmax_t	i;

	i = va_arg(ap, intmax_t);
	if (data->flag & F_L)
		i = (long)i;
	else if (data->flag & F_LL)
		i = (long long)i;
	else if (data->flag & F_H)
		i = (short int)i;
	else if (data->flag & F_HH)
		i = (char)i;
	else if (data->flag & F_J)
		i = (intmax_t)i;
	else if (data->flag & F_Z)
		i = (ssize_t)i;
	else
		i = (int)i;
	data->arg = pf_itoa_base(i, 10);
	data->size = pf_strlen(data->arg);
	data->arg = modify_conv(i, data);
	add_to_buf(data);
	data->buf = pf_strjoin(data->buf, data->arg, data);
	return (data->size);
}
