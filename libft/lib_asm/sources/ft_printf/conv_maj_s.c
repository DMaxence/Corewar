/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_maj_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/31 15:26:31 by bvigne           ###   ########.fr       */
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

static char		*modify_conv(t_arg *data)
{
	if (data->larg > data->size)
		data->arg = modif_larg(data);
	return (data->arg);
}

static int		get_uni(wchar_t c, char **res, t_arg *data)
{
	if (parse_exep(c, res, data) == 0)
		return (-1);
	if (c <= 127)
		return (first_uni(c, res));
	else if (c <= 0x7FF)
		return (second_uni(c, res, data, 'S'));
	else if (c <= 0xFFFF)
		return (third_uni(c, res, data, 'S'));
	else if (c <= 0x10FFFF)
		return (fourth_uni(c, res, data, 'S'));
	pf_strdel(res);
	pf_strdel(&data->arg);
	return (-1);
}

int				conv_maj_s(t_arg *data, va_list ap)
{
	wchar_t			*s;
	char			*res;
	int				i;

	i = 0;
	s = va_arg(ap, wchar_t *);
	if (s == NULL)
		data->arg = pf_strdup("(null)");
	else
		data->arg = pf_strdup("");
	while (s && s[i] != 0)
	{
		res = pf_strnew(5);
		if ((data->size = get_uni(s[i], &res, data)) == -1)
			return (-1);
		if (data->preci == -1 || (data->preci >= 0 && (int)(pf_strlen(data->arg)
		+ pf_strlen(res)) <= data->preci))
			data->arg = pf_spejoin(data->arg, res, data);
		i++;
	}
	data->size = pf_strlen(data->arg);
	data->arg = modify_conv(data);
	add_to_buf(data);
	data->buf = pf_strjoin(data->buf, data->arg, data);
	return (data->size);
}
