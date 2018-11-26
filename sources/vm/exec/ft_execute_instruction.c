/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 16:48:03 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/06 11:31:43 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

int		ft_execute_instruction(t_stock *s, t_process *p)
{
	if ((s->memory[p->pc] == 0x01 && ft_live(s, p))
			|| (s->memory[p->pc] == 0x02 && ft_ld(s, p))
			|| (s->memory[p->pc] == 0x03 && ft_st(s, p))
			|| (s->memory[p->pc] == 0x04 && ft_add(s, p))
			|| (s->memory[p->pc] == 0x05 && ft_sub(s, p))
			|| (s->memory[p->pc] == 0x06 && ft_and(s, p))
			|| (s->memory[p->pc] == 0x07 && ft_or(s, p))
			|| (s->memory[p->pc] == 0x08 && ft_xor(s, p))
			|| (s->memory[p->pc] == 0x09 && ft_zjmp(s, p))
			|| (s->memory[p->pc] == 0x0A && ft_ldi(s, p))
			|| (s->memory[p->pc] == 0x0B && ft_sti(s, p))
			|| (s->memory[p->pc] == 0x0C && ft_fork(s, p))
			|| (s->memory[p->pc] == 0x0D && ft_lld(s, p))
			|| (s->memory[p->pc] == 0x0E && ft_lldi(s, p))
			|| (s->memory[p->pc] == 0x0F && ft_lfork(s, p))
			|| (s->memory[p->pc] == 0x10 && ft_aff(s, p)))
		return (1);
	return (0);
}
