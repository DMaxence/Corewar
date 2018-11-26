/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchen <mchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:27:23 by mchen             #+#    #+#             */
/*   Updated: 2018/05/30 18:49:10 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			add_to_buf(t_arg *data)
{
	if (data->reg != NULL)
	{
		data->lreg = pf_strlen(data->reg);
		data->buf = pf_regjoin(data->buf, data->reg, data);
		data->len += data->lreg;
	}
}

void			get_len(char *format, va_list ap, t_arg *data)
{
	int		i;

	data->len = 0;
	data->size = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				break ;
			data->reg = pf_strndup(format, i);
			format += i + 1;
			i = parse_index(format, ap, data);
			if (i == -1)
				return ;
			data->size = 0;
			format += i;
			i = 0;
		}
		else
			i++;
	}
	data->reg = pf_strndup(format, i);
	add_to_buf(data);
}
