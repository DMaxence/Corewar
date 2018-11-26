/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:52:53 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/30 18:41:43 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		check_att(t_arg *data)
{
	int		i;

	i = 0;
	if (data->flag & F_L)
		i++;
	if (data->flag & F_LL)
		i++;
	if (data->flag & F_H)
		i++;
	if (data->flag & F_HH)
		i++;
	if (data->flag & F_J)
		i++;
	if (data->flag & F_Z)
		i++;
	return (i);
}

static void		last_check(char conv, t_arg *data)
{
	int		i;

	i = check_att(data);
	if (i >= 2)
	{
		data->flag &= ~F_L;
		data->flag &= ~F_LL;
		data->flag &= ~F_H;
		data->flag &= ~F_HH;
		data->flag &= ~F_Z;
		data->flag |= F_J;
	}
	if ((data->preci >= 0 && conv != 'c' && conv != 'C' && conv != 's' &&
	conv != 'S') || data->flag & F_MINUS)
		data->flag &= ~F_ZERO;
	if (data->flag & F_SPACE && data->flag & F_PLUS)
		data->flag &= ~F_SPACE;
}

static int		loop_parse(char *fmt, int i, t_arg *data, va_list ap)
{
	if (pf_strchr(ATT_LST, fmt[i]))
		i += get_att(fmt + i, data);
	else if (pf_strchr(MOD_LST, fmt[i]))
		i += get_mod(fmt + i, data);
	else if ((pf_isdigit(fmt[i]) && fmt[i] != '0') || fmt[i] == '*')
		i += get_width(fmt + i, data, ap);
	else if (fmt[i] == '.')
		i += get_pre(fmt + i, data, ap);
	return (i);
}

static int		init_parse(char *fmt, t_arg *data)
{
	data->flag = 0;
	data->preci = -1;
	data->larg = 0;
	if (fmt[0] == '%')
	{
		add_to_buf(data);
		data->arg = pf_strdup("%");
		data->size = 1;
		data->buf = pf_strjoin(data->buf, data->arg, data);
		data->len += 1;
		return (0);
	}
	else if (fmt[0] == 0)
	{
		add_to_buf(data);
		return (0);
	}
	return (1);
}

int				parse_index(char *fmt, va_list ap, t_arg *data)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (init_parse(fmt, data) == 0)
		return (1);
	while (fmt[i] && (pf_strchr(ALL_CHAR, fmt[i])))
		i = loop_parse(fmt, i, data, ap);
	if (fmt[i] && pf_strchr(CONV_LST, fmt[i]))
	{
		last_check(fmt[i], data);
		size = convert(fmt + i, ap, data);
		if (size == -1)
			return (-1);
		else
			data->len += size;
		i++;
	}
	else if (fmt[i])
		i += conv_none(fmt[i], data);
	return (i);
}
