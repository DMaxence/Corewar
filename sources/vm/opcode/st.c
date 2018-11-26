/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:35:49 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/06 10:56:33 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

/*
**	0x03
*/

static char		ft_verif_ocp(char ocp)
{
	if ((ocp & 0xc0) >> 6 != REG_CODE
			|| ((ocp & 0x30) >> 4 != REG_CODE
				&& (ocp & 0x30) >> 4 != IND_CODE)
			|| (ocp & 0x0c) >> 2 != 0
			|| (ocp & 0x03) != 0)
		return (0);
	return (ocp);
}

int				ft_st(t_stock *s, t_process *p)
{
	char		ocp;
	int			nb;

	if (!(ocp = ft_verif_ocp(s->memory[(p->pc + 1) % MEM_SIZE]))
			|| !ft_verif_reg(s->memory[(p->pc + 2) % MEM_SIZE]))
		return (0);
	nb = p->registre[(int)s->memory[(p->pc + 2) % MEM_SIZE] - 1];
	if ((ocp & 0x30) >> 4 == REG_CODE)
	{
		if (!ft_verif_reg(s->memory[(p->pc + 3) % MEM_SIZE]))
			return (0);
		p->registre[(int)s->memory[(p->pc + 3) % MEM_SIZE] - 1] = nb;
	}
	else if ((ocp & 0x30) >> 4 == IND_CODE)
	{
		write_idx(s, p, 3, nb);
		write_idx_rgb(s, p, 3, p->id);
	}
	return (1);
}
