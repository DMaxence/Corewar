/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:39:44 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/06 11:23:28 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

/*
**		0x04
*/

static char		ft_verif_ocp(char ocp)
{
	if ((ocp & 0xc0) >> 6 != REG_CODE
			|| (ocp & 0x30) >> 4 != REG_CODE
			|| (ocp & 0x0c) >> 2 != REG_CODE
			|| (ocp & 0x03) != 0)
		return (0);
	return (1);
}

int				ft_add(t_stock *s, t_process *p)
{
	char		ocp;

	if (!(ocp = ft_verif_ocp(s->memory[(p->pc + 1) % MEM_SIZE]))
			|| !ft_verif_reg(s->memory[(p->pc + 2) % MEM_SIZE])
			|| !ft_verif_reg(s->memory[(p->pc + 3) % MEM_SIZE])
			|| !ft_verif_reg(s->memory[(p->pc + 4) % MEM_SIZE]))
		return (0);
	if ((p->registre[(int)s->memory[(p->pc + 4) % MEM_SIZE] - 1] =
			p->registre[(int)s->memory[(p->pc + 3) % MEM_SIZE] - 1]
			+ p->registre[(int)s->memory[(p->pc + 2) % MEM_SIZE] - 1]) == 0)
		p->carry = 1;
	else
		p->carry = 0;
	return (1);
}
