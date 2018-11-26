/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 15:55:45 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void					toto(int pos, int n, char *arg, t_asm *prog)
{
	int						j;
	char					split[3];

	j = 0;
	while (j < prog->byte[pos].param[n].noct)
	{
		ft_strncpy(split, arg + j * 2, 2);
		prog->cor[prog->i] = ft_atobase(split, "0123456789abcdef");
		ft_bzero(split, 3);
		j++;
		prog->i++;
	}
}

static int					fill_arg(int pos, t_asm *prog)
{
	int						n;
	char					*arg;

	n = 0;
	while (n < prog->pro[pos].nb_arg)
	{
		if (!(arg = (char *)malloc(sizeof(char) *
		prog->byte[pos].param[n].noct * 2)))
		{
			prog->err.code = MLC_ERR;
			return (1);
		}
		ft_sprintf(arg, "%0*x", prog->byte[pos].param[n].noct * 2,
		prog->byte[pos].param[n].val);
		if (prog->byte[pos].param[n].noct == 2 && ft_strlen(arg) > 4)
			toto(pos, n, arg + ft_strlen(arg) - 4, prog);
		else
			toto(pos, n, arg, prog);
		ft_strdel(&arg);
		n++;
	}
	return (0);
}

static int					fill_inst_oct(int pos, t_asm *prog)
{
	char					split[9];

	prog->cor[prog->i] = prog->byte[pos].inst;
	prog->i++;
	if (prog->byte[pos].oct)
	{
		ft_sprintf(split, "%08d", prog->byte[pos].oct);
		prog->cor[prog->i] = ft_atobase(split, "01");
		prog->i++;
	}
	return (0);
}

int							byte_step(t_asm *prog)
{
	int						pos;

	pos = 0;
	while (pos < prog->line)
	{
		if (prog->byte[pos].nb_oct != 0)
		{
			if (fill_inst_oct(pos, prog))
				return (1);
			if (fill_arg(pos, prog))
				return (1);
		}
		pos++;
	}
	return (0);
}
