/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:52:17 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/17 17:27:29 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pf_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	while (i <= (int)size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*pf_strdup(char *src)
{
	char	*dest;
	int		size;
	int		i;

	size = 0;
	while (src[size])
		size++;
	if (!(dest = (char *)malloc(sizeof(*src) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && (dest[i] || src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*pf_strndup(const char *src, int nb)
{
	char	*dest;
	int		i;

	if (!(dest = (char *)malloc(sizeof(*src) * (nb + 1))))
		return (NULL);
	i = 0;
	while (i < nb)
	{
		if (src[i])
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*pf_strncat(char *dest, char *src, int l_dest, int l_src)
{
	int		i;

	i = 0;
	while (l_src)
	{
		dest[l_dest] = src[i];
		l_dest++;
		i++;
		l_src--;
	}
	dest[l_dest] = '\0';
	return (dest);
}

char	*pf_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (src[i])
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
