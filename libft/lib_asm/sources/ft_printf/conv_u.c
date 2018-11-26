/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/29 15:15:26 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*modif_larg(t_arg *data)
{
	if (data->flag & F_ZERO)
		data->arg = pf_x_join(data->larg - data->size, '0', data->size, data);
	else if (data->flag & F_MINUS)
		data->arg = pf_join_x(data->larg - data->size, ' ', data->size, data);
	else
		data->arg = pf_x_join(data->larg - data->size, ' ', data->size, data);
	return (data->arg);
}

static char		*modif_preci(t_arg *data)
{
	if (data->preci > data->size)
		data->arg = pf_x_join(data->preci - data->size, '0', data->size, data);
	return (data->arg);
}

static char		*modify_conv(uintmax_t i, t_arg *data)
{
	if (data->preci == 0 && i == 0 && !(data->flag & F_HASH))
	{
		pf_strdel(&data->arg);
		data->arg = pf_strdup("");
		data->size = 0;
	}
	if (data->preci >= 0)
		data->arg = modif_preci(data);
	if (data->larg > (int)pf_strlen(data->arg))
		data->arg = modif_larg(data);
	return (data->arg);
}

int				conv_u(t_arg *data, va_list ap)
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
	else if (data->flag & F_Z)
		i = (size_t)i;
	else if (data->flag & F_J)
		i = (uintmax_t)i;
	else
		i = (unsigned int)i;
	data->arg = pf_utoa_base(i, 10);
	data->size = pf_strlen(data->arg);
	data->arg = modify_conv(i, data);
	add_to_buf(data);
	data->buf = pf_strjoin(data->buf, data->arg, data);
	return (data->size);
}
