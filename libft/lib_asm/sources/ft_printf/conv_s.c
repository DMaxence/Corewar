/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/31 15:26:32 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*modif_preci(t_arg *data)
{
	char	*tmp;

	tmp = NULL;
	tmp = pf_strndup(data->arg, data->preci);
	data->size = data->preci;
	pf_strdel(&data->arg);
	return (tmp);
}

static char		*modify_conv(t_arg *data)
{
	if (data->preci >= 0 && data->preci < data->size)
		data->arg = modif_preci(data);
	if (data->larg > data->size)
	{
		if (data->flag & F_ZERO)
			data->arg = pf_x_join(data->larg - data->size, '0', data->size,
			data);
		else if (data->flag & F_MINUS)
			data->arg = pf_join_x(data->larg - data->size, ' ', data->size,
			data);
		else
			data->arg = pf_x_join(data->larg - data->size, ' ', data->size,
			data);
	}
	return (data->arg);
}

static int		get_uni(wchar_t c, char **res, t_arg *data)
{
	if (parse_exep(c, res, data) == 0)
		return (-1);
	if (c <= 127)
		return (first_uni(c, res));
	else if (c <= 0x7FF)
		return (second_uni(c, res, data, 's'));
	else if (c <= 0xFFFF)
		return (third_uni(c, res, data, 's'));
	else if (c <= 0x10FFFF)
		return (fourth_uni(c, res, data, 's'));
	pf_strdel(res);
	pf_strdel(&data->arg);
	return (-1);
}

static int		loop_uni(wchar_t *ws, t_arg *data)
{
	int		i;
	char	*res;

	i = 0;
	while (ws && ws[i] != 0)
	{
		res = pf_strnew(5);
		if ((data->size = get_uni(ws[i], &res, data)) == -1)
			return (-1);
		if (data->preci == -1 || (data->preci >= 0 && (int)(pf_strlen(data->arg)
		+ pf_strlen(res)) <= data->preci))
			data->arg = pf_spejoin(data->arg, res, data);
		else
		{
			pf_strdel(&res);
			break ;
		}
		i++;
	}
	return (pf_strlen(data->arg));
}

int				conv_s(t_arg *data, va_list ap)
{
	wchar_t	*ws;
	char	*s;

	ws = NULL;
	s = NULL;
	if (data->flag & F_L)
		ws = va_arg(ap, wchar_t *);
	else
		s = va_arg(ap, char *);
	if ((!(data->flag & F_L) && s == NULL) || (data->flag & F_L && ws == NULL))
		data->arg = pf_strdup("(null)");
	else if (!(data->flag & F_L))
		data->arg = pf_strdup(s);
	else
		data->arg = pf_strdup("");
	if (ws != NULL && (data->size = loop_uni(ws, data)) == -1)
		return (-1);
	else
		data->size = pf_strlen(data->arg);
	data->arg = modify_conv(data);
	add_to_buf(data);
	data->buf = pf_strjoin(data->buf, data->arg, data);
	return (data->size);
}
