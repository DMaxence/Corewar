/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:11:50 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/22 15:49:05 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"
#include "../../../includes/visu.h"

static void		ft_next_instruction_bis(t_stock *s, t_process *p, char inst)
{
	char	ocp;
	short	d2_or_d4;

	ocp = s->memory[(p->pc + 1) % MEM_SIZE];
	d2_or_d4 = 4;
	if (inst == 0x0a || inst == 0x0b || inst == 0x0e)
		d2_or_d4 = 2;
	while (ocp)
	{
		if ((ocp & 0x03) == REG_CODE)
			p->pc = (p->pc + 1) % MEM_SIZE;
		else if ((ocp & 0x03) == DIR_CODE)
			p->pc = (p->pc + d2_or_d4) % MEM_SIZE;
		else if ((ocp & 0x03) == IND_CODE)
			p->pc = (p->pc + 2) % MEM_SIZE;
		ocp = ((ocp & 0xfc) >> 2) & 0x3f;
	}
	p->pc = (p->pc + 2) % MEM_SIZE;
}

void			ft_next_instruction(t_stock *s, t_process *p, char inst)
{
	if (!inst || inst > 0x10)
		p->pc = (p->pc + 1) % MEM_SIZE;
	else if (inst == 0x01)
		p->pc = (p->pc + 5) % MEM_SIZE;
	else if (inst == 0x09 || inst == 0x0c || inst == 0x0f)
		p->pc = (p->pc + 3) % MEM_SIZE;
	else
		ft_next_instruction_bis(s, p, inst);
}

void			ft_first_play(t_stock *s)
{
	t_process	*tmp;

	tmp = s->begin_lst;
	while (tmp)
	{
		ft_wait_instruction(tmp, s->memory[tmp->pc]);
		tmp = tmp->next;
	}
}

void			ft_print_dump(t_stock *s)
{
	int		i;
	int		j;

	i = -1;
	ft_printf("\nend because of -dump cycle : %d\n", s->cycle);
	ft_printnchar(97, '-');
	ft_printf("MEMORY");
	ft_printnchar(97, '-');
	while (++i < 64)
	{
		j = -1;
		ft_printf("\n0x%04x : ", i * 64);
		while (++j < 64)
			ft_printf("%02x ", (s->memory[(i * 64) + j]) & 0xff);
	}
	ft_putchar('\n');
	ft_printnchar(200, '-');
	i = -1;
	while (++i < s->nb_player)
		ft_printf("\nplayer %s live(s) for the current cycle %d",
				s->champ[i]->header->prog_name, s->champ[i]->live);
	ft_putchar('\n');
}
