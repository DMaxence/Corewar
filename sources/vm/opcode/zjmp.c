/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:31:00 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/08 16:17:29 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

/*
**	0x09
*/

int		ft_zjmp(t_stock *s, t_process *p)
{
	int		where;

	if (p->carry == 1)
	{
		where = ft_index_pc(ft_idx(read_direct(2, s, p, 1)), p->pc);
		p->pc = where;
		ft_wait_instruction(p, s->memory[p->pc]);
	}
	return (1);
}
