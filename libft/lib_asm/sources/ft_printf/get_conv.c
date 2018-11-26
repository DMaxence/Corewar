/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:52:53 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/30 17:36:47 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_conv		g_conv[] =
{
	{'c', &conv_c},
	{'C', &conv_maj_c},
	{'s', &conv_s},
	{'S', &conv_maj_s},
	{'i', &conv_i},
	{'d', &conv_i},
	{'D', &conv_maj_d},
	{'u', &conv_u},
	{'U', &conv_maj_u},
	{'x', &conv_x},
	{'X', &conv_maj_x},
	{'o', &conv_o},
	{'O', &conv_maj_o},
	{'p', &conv_p},
	{0, NULL},
};

int			convert(char *fmt, va_list ap, t_arg *data)
{
	size_t	i;
	int		size;

	i = 0;
	size = 0;
	data->size = 0;
	while (g_conv[i].conv && i < pf_strlen(CONV_LST) + 1)
	{
		if (fmt[0] == g_conv[i].conv)
		{
			size = g_conv[i].f(data, ap);
			break ;
		}
		i++;
	}
	return (size);
}
