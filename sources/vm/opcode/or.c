/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:39:44 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/06 10:54:10 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

/*
**		0x07
*/

static char		ft_verif_ocp(char ocp)
{
	if (((ocp & 0xc0) >> 6 != REG_CODE
				&& (ocp & 0xc0) >> 6 != IND_CODE
				&& (ocp & 0xc0) >> 6 != DIR_CODE)
			|| ((ocp & 0x30) >> 4 != REG_CODE
				&& (ocp & 0x30) >> 4 != IND_CODE
				&& (ocp & 0x30) >> 4 != DIR_CODE)
			|| (ocp & 0x0c) >> 2 != REG_CODE
			|| (ocp & 0x03) != 0)
		return (0);
	return (ocp);
}

static int		ft_get_param1(t_stock *s, t_process *p, int *i, int *param)
{
	char		ocp;

	ocp = (s->memory[p->pc + 1] & 0xc0) >> 6;
	if (ocp == REG_CODE)
	{
		if (!ft_verif_reg(s->memory[p->pc + *i]))
			return (0);
		*param = p->registre[(int)s->memory[p->pc + *i] - 1];
		*i += 1;
	}
	else if (ocp == IND_CODE)
	{
		*param = read_index(s, p, *i, 1);
		*i += 2;
	}
	else if (ocp == DIR_CODE)
	{
		*param = read_direct(4, s, p, *i);
		*i += 4;
	}
	return (1);
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
		*param = read_index(s, p, *i, 1);
		*i += 2;
	}
	else if (ocp == DIR_CODE)
	{
		*param = read_direct(4, s, p, *i);
		*i += 4;
	}
	return (1);
}

int				ft_or(t_stock *s, t_process *p)
{
	int			param1;
	int			param2;
	int			index;
	char		ocp;

	index = 2;
	if (!(ocp = ft_verif_ocp(s->memory[(p->pc + 1) % MEM_SIZE]))
			|| !ft_get_param1(s, p, &index, &param1)
			|| !ft_get_param2(s, p, &index, &param2))
		return (0);
	if (!(p->registre[(int)s->memory[p->pc + index] - 1] = param1 | param2))
		p->carry = 1;
	else
		p->carry = 0;
	return (1);
}
