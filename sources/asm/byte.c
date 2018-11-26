/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 15:55:35 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void				fill_ret(t_param *ret, int pos, int idx, t_argu *arg)
{
	int					lab;
	int					dir;

	lab = 0;
	dir = 0;
	if (ft_strnchar(LABEL_CHAR, arg[pos].arg))
		lab = 1;
	if (ft_strnchar(DIRECT_CHAR, arg[pos].arg))
	{
		dir = 1;
		if (idx == 1)
			ret[pos].noct = 2;
		else
			ret[pos].noct = 4;
	}
	else
		ret[pos].noct = 2;
	if (lab == 1)
		ret[pos].val = 0;
	else
		ret[pos].val = ft_atoi(arg[pos].arg + dir);
	return ;
}

static t_param			*conv_arg(int i, int idx, t_asm *prog)
{
	int					pos;
	t_param				*ret;

	pos = 0;
	if (!(ret = (t_param *)malloc(sizeof(t_param) * (prog->pro[i].nb_arg))))
	{
		prog->err.code = MLC_ERR;
		return (NULL);
	}
	while (pos < prog->pro[i].nb_arg)
	{
		if (prog->pro[i].arg[pos].type == 1)
		{
			ret[pos].noct = 1;
			ret[pos].val = ft_atoi(prog->pro[i].arg[pos].arg + 1);
		}
		else
			fill_ret(ret, pos, idx, prog->pro[i].arg);
		prog->byte[i].nb_oct += ret[pos].noct;
		pos++;
	}
	return (ret);
}

static int				fill_oct(t_pro pro)
{
	int					nb;
	int					pos;
	int					ret;

	ret = 0;
	nb = 1000000;
	pos = 0;
	while (pos < pro.nb_arg)
	{
		if (pro.arg[pos].type == 1)
			ret += (1 * nb);
		else if (pro.arg[pos].type == 2)
			ret += (10 * nb);
		else
			ret += (11 * nb);
		nb /= 100;
		pos++;
	}
	return (ret);
}

int						fill_byte(int pos, t_asm *prog)
{
	int					i;

	i = 0;
	while (g_op_tab[i].opcode != 0)
	{
		if (ft_strcmp(prog->pro[pos].opc, g_op_tab[i].instruction) == 0)
		{
			prog->byte[pos].inst = g_op_tab[i].opcode;
			prog->byte[pos].nb_oct = 1;
			if (g_op_tab[i].oct_cod)
			{
				prog->byte[pos].oct = fill_oct(prog->pro[pos]);
				prog->byte[pos].nb_oct++;
			}
			else
				prog->byte[pos].oct = 0;
			prog->byte[pos].param = conv_arg(pos, g_op_tab[i].haveindex, prog);
		}
		i++;
	}
	return (0);
}
