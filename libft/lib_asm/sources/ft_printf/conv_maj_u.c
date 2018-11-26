/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_maj_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/29 15:15:00 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*modif_larg(t_arg *data)
{
	if (data->flag & F_ZERO)
		data->arg = pf_x_join(data->larg - data->size, '0', data->size,
		data);
	if (data->flag & F_MINUS)
		data->arg = pf_join_x(data->larg - data->size, ' ', data->size,
		data);
	if (data->flag & F_SPACE)
		data->arg = pf_x_join(1, ' ', data->size, data);
	data->arg = pf_x_join(data->larg - data->size, ' ', data->size,
	data);
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
	if (data->preci > data->size)
		data->arg = pf_x_join(data->preci - data->size, '0', data->size,
		data);
	if (data->larg > data->size)
		data->arg = modif_larg(data);
	return (data->arg);
}

int				conv_maj_u(t_arg *data, va_list ap)
{
	uintmax_t	i;

	i = va_arg(ap, unsigned long);
	data->arg = pf_utoa_base(i, 10);
	data->size = pf_strlen(data->arg);
	data->arg = modify_conv(i, data);
	add_to_buf(data);
	data->buf = pf_strjoin(data->buf, data->arg, data);
	return (data->size);
}
