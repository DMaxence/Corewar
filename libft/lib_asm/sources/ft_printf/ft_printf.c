/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchen <mchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:27:23 by mchen             #+#    #+#             */
/*   Updated: 2018/05/31 15:26:28 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_arg		data;

	va_start(ap, format);
	data.buf = pf_strdup("");
	get_len((char *)format, ap, &data);
	va_end(ap);
	write(1, data.buf, data.len);
	pf_strdel(&data.buf);
	if (data.size < 0)
		return (-1);
	return (data.len);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	t_arg		data;

	va_start(ap, format);
	data.buf = pf_strdup("");
	get_len((char *)format, ap, &data);
	va_end(ap);
	write(fd, data.buf, data.len);
	pf_strdel(&data.buf);
	if (data.size < 0)
		return (-1);
	return (data.len);
}

int				ft_dnprintf(int fd, int s, const char *format, ...)
{
	va_list		ap;
	t_arg		data;

	va_start(ap, format);
	data.buf = pf_strdup("");
	get_len((char *)format, ap, &data);
	va_end(ap);
	if (data.len < s)
		data.len = s;
	write(fd, data.buf, data.len);
	pf_strdel(&data.buf);
	if (data.size < 0)
		return (-1);
	return (data.len);
}

int				ft_sprintf(char *str, const char *format, ...)
{
	va_list		ap;
	t_arg		data;

	va_start(ap, format);
	data.buf = pf_strdup("");
	get_len((char *)format, ap, &data);
	va_end(ap);
	str = pf_strncpy(str, data.buf, data.len);
	pf_strdel(&data.buf);
	if (data.size < 0)
		return (-1);
	return (data.len);
}

int				ft_snprintf(char *str, int s, const char *format, ...)
{
	va_list		ap;
	t_arg		data;

	va_start(ap, format);
	data.buf = pf_strdup("");
	get_len((char *)format, ap, &data);
	va_end(ap);
	str = pf_strncpy(str, data.buf, s - 1);
	pf_strdel(&data.buf);
	if (data.size < 0)
		return (-1);
	return (data.len);
}
