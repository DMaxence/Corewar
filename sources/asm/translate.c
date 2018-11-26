/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 16:01:24 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static int				alloc_byte_and_param(t_asm *prog)
{
	if (!(prog->byte = (t_byte *)malloc(sizeof(t_byte)
		* (prog->line + 1))))
	{
		prog->err.code = MLC_ERR;
		return (1);
	}
	return (0);
}

void					translate(t_asm *prog)
{
	int					i;

	i = 0;
	if (alloc_byte_and_param(prog))
		return ;
	while (i < prog->line)
	{
		if (prog->pro[i].nb_arg != 0)
		{
			if (fill_byte(i, prog))
				return ;
		}
		else
		{
			prog->byte[i].inst = 0;
			prog->byte[i].oct = 0;
			prog->byte[i].nb_oct = 0;
		}
		i++;
	}
	fill_jump(prog);
}
