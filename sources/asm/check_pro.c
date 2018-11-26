/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 15:55:55 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static int				parse_arg(t_argu *arg, int pos, int mod, t_asm *prog)
{
	int					ret;

	ret = 0;
	if (arg[pos].arg[0] == 'r')
		ret = reg_arg(arg[pos].arg, mod);
	else if (arg[pos].arg[0] == DIRECT_CHAR)
		ret = dir_arg(arg[pos].arg, mod, prog);
	else if ((arg[pos].arg[0] >= '0' && arg[pos].arg[0] <= '9')
		|| arg[pos].arg[0] == '-' || arg[pos].arg[0] == LABEL_CHAR)
		ret = ind_arg(arg[pos].arg, mod, prog);
	arg[pos].type = ret;
	return (ret);
}

static int				look_args(t_pro pro, int pos, t_asm *prog)
{
	int					i;
	int					mod;
	int					ret;

	i = 0;
	ret = 0;
	while (g_op_tab[i].opcode != 0)
	{
		if (ft_strcmp(pro.opc, g_op_tab[i].instruction) == 0)
		{
			mod = g_op_tab[i].arg_mod[pos];
			ret = parse_arg(pro.arg, pos, mod, prog);
			break ;
		}
		i++;
	}
	return (ret);
}

void					check_pro(t_asm *prog)
{
	int					i;
	int					pos;

	i = 0;
	while (i < prog->line)
	{
		pos = 0;
		while (pos < prog->pro[i].nb_arg)
		{
			if (look_args(prog->pro[i], pos, prog) == 0)
			{
				prog->err.code = ARG_ERR;
				return ;
			}
			pos++;
		}
		i++;
	}
}
