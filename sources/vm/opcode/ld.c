/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:35:49 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/21 15:17:30 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

/*
**	0x02
*/

static char		ft_verif_ocp(char ocp)
{
	if (((ocp & 0xc0) >> 6 != IND_CODE
				&& (ocp & 0xc0) >> 6 != DIR_CODE)
			|| (ocp & 0x30) >> 4 != REG_CODE
			|| (ocp & 0x0c) >> 2 != 0
			|| (ocp & 0x0c) != 0)
		return (0);
	return (ocp);
}

static int		ft_get_param1(t_stock *s, t_process *p, int *i, int *param)
{
	char		ocp;

	ocp = (s->memory[p->pc + 1] & 0xc0) >> 6;
	if (ocp == IND_CODE)
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

int				ft_ld(t_stock *s, t_process *p)
{
	char		ocp;
	int			index;
	int			param1;

	index = 2;
	if (!(ocp = ft_verif_ocp(s->memory[(p->pc + 1) % MEM_SIZE]))
			|| !ft_get_param1(s, p, &index, &param1)
			|| !ft_verif_reg(s->memory[(p->pc + index) % MEM_SIZE]))
		return (0);
	p->registre[(int)s->memory[(p->pc + index) % MEM_SIZE] - 1] = param1;
	if (!param1)
		p->carry = 1;
	else
		p->carry = 0;
	return (1);
}
