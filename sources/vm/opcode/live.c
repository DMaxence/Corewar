/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 12:19:47 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/21 18:28:43 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

/*
**	0x01
*/

static int		live_bis(t_stock *s, t_process *p, int d4, int i)
{
	s->champ[i]->live += 1;
	s->champ[i]->last_live[i] = s->cycle;
	s->last_champ_live = d4;
	if (s->opt_v == 1)
	{
		s->rgb[p->pc % MEM_SIZE].rgb = p->id * 10;
		s->rgb[p->pc % MEM_SIZE].player = p->id;
		s->rgb[p->pc % MEM_SIZE].cycle = s->cycle;
		s->rgb[p->pc % MEM_SIZE].time_to_live = 80;
	}
	return (1);
}

int				ft_live(t_stock *s, t_process *p)
{
	int			i;
	int			d4;

	i = -1;
	s->total_nbr_live += 1;
	d4 = read_direct(4, s, p, 1);
	p->live = 1;
	while (++i < s->nb_player)
		if (s->champ[i]->nb_player == d4)
			return (live_bis(s, p, d4, i));
	return (0);
}
