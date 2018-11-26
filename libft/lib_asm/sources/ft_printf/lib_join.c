/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/30 14:23:01 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pf_strjoin(char *s1, char *s2, t_arg *data)
{
	char	*res;

	res = NULL;
	if (!(res = pf_strnew(data->len + data->size + 1)))
		return (NULL);
	pf_strncpy(res, s1, data->len);
	pf_strncat(res, s2, data->len, data->size);
	pf_strdel(&s1);
	pf_strdel(&s2);
	return (res);
}

char	*pf_regjoin(char *s1, char *s2, t_arg *data)
{
	char	*res;

	res = NULL;
	if (!(res = pf_strnew(data->len + data->lreg + 1)))
		return (NULL);
	pf_strncpy(res, s1, data->len);
	pf_strncat(res, s2, data->len, data->lreg);
	pf_strdel(&s1);
	pf_strdel(&s2);
	return (res);
}

char	*pf_spejoin(char *s1, char *s2, t_arg *data)
{
	char	*res;

	res = NULL;
	if (!(res = pf_strnew(pf_strlen(s1) + data->size + 1)))
		return (NULL);
	pf_strncpy(res, s1, pf_strlen(s1));
	pf_strncat(res, s2, pf_strlen(s1), data->size);
	pf_strdel(&s1);
	pf_strdel(&s2);
	return (res);
}

char	*pf_x_join(int n, char c, int size, t_arg *data)
{
	char	*res;
	char	*add;
	int		i;

	i = 0;
	res = NULL;
	data->size += n;
	if (!(add = (char *)malloc(sizeof(*add) * (n + 1))))
		return (NULL);
	while (n > 0)
	{
		add[i++] = c;
		n--;
	}
	add[i] = '\0';
	if (!(res = pf_strnew(data->size + 1)))
		return (NULL);
	pf_strncpy(res, add, pf_strlen((char *)add));
	pf_strncat(res, data->arg, pf_strlen((char *)add), size);
	pf_strdel(&data->arg);
	pf_strdel(&add);
	return (res);
}

char	*pf_join_x(int n, char c, int size, t_arg *data)
{
	char	*res;
	char	*add;
	int		i;

	i = 0;
	res = NULL;
	data->size += n;
	if (!(add = (char *)malloc(sizeof(*add) * (n + 1))))
		return (NULL);
	while (n > 0)
	{
		add[i++] = c;
		n--;
	}
	add[i] = '\0';
	if (!(res = pf_strnew(data->size + 1)))
		return (NULL);
	pf_strncpy(res, data->arg, size);
	pf_strncat(res, add, size, pf_strlen(add));
	pf_strdel(&data->arg);
	pf_strdel(&add);
	return (res);
}
