/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:39:44 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/06 10:52:29 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

/*
**		0x0B
*/

static char		ft_verif_ocp(char ocp)
{
	if ((ocp & 0xc0) >> 6 != REG_CODE
			|| ((ocp & 0x30) >> 4 != REG_CODE
				&& (ocp & 0x30) >> 4 != IND_CODE
				&& (ocp & 0x30) >> 4 != DIR_CODE)
			|| ((ocp & 0x0c) >> 2 != REG_CODE
				&& (ocp & 0x0c) >> 2 != DIR_CODE)
			|| (ocp & 0x03) != 0)
		return (0);
	return (ocp);
}

static int		ft_get_param2(t_stock *s, t_process *p, int *i, int *param)
{
	char		ocp;

	ocp = (s->memory[p->pc + 1] & 0x30) >> 4;
	if (ocp == REG_CODE)
	{
		if (!ft_verif_reg(s->memory[p->pc + *i]))
			return (0);
		*param = p->registre[(int)s->memory[p->pc + *i] - 1];
		*i += 1;
	}
	else if (ocp == IND_CODE)
	{
		*param = read_direct(2, s, p, *i);
		*i += 2;
	}
	else if (ocp == DIR_CODE)
	{
		*param = read_direct(2, s, p, *i);
		*i += 2;
	}
	return (1);
}

static int		ft_get_param3(t_stock *s, t_process *p, int *i, int *param)
{
	char		ocp;

	ocp = (s->memory[p->pc + 1] & 0x0c) >> 2;
	if (ocp == REG_CODE)
	{
		if (!ft_verif_reg(s->memory[p->pc + *i]))
			return (0);
		*param = p->registre[(int)s->memory[p->pc + *i] - 1];
		*i += 1;
	}
	else if (ocp == IND_CODE)
	{
		*param = read_direct(2, s, p, *i);
		*i += 2;
	}
	else if (ocp == DIR_CODE)
	{
		*param = read_direct(2, s, p, *i);
		*i += 2;
	}
	return (1);
}

int				ft_sti(t_stock *s, t_process *p)
{
	int			index;
	int			param2;
	int			param3;
	int			address;

	index = 3;
	if (!(ft_verif_ocp(s->memory[(p->pc + 1) % MEM_SIZE]))
			|| !ft_verif_reg(s->memory[(p->pc + 2) % MEM_SIZE])
			|| !ft_get_param2(s, p, &index, &param2)
			|| !ft_get_param3(s, p, &index, &param3))
		return (0);
	address = ft_index_pc(ft_idx((param2 + param3) % MEM_SIZE), p->pc);
	write_nb(s, address,
			p->registre[(int)s->memory[(p->pc + 2) % MEM_SIZE] - 1]);
	if (s->opt_v)
		write_nb_rgb(s, address, p->id);
	return (1);
}
