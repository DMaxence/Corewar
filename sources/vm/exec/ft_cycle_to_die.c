/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle_to_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:11:50 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/21 14:47:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static void	ft_free_process(t_process *process)
{
	ft_strdel(&process->aff);
	free(process);
	process = NULL;
}

static void	ft_begin_lst_dead(t_stock *s)
{
	t_process	*tmp;

	while (s->begin_lst && !s->begin_lst->live)
	{
		tmp = s->begin_lst;
		s->begin_lst = s->begin_lst->next;
		ft_free_process(tmp);
	}
	if (s->begin_lst)
		s->begin_lst->live = 0;
}

static void	ft_clean_process(t_stock *s)
{
	t_process	*p1;
	t_process	*p2;

	ft_begin_lst_dead(s);
	p1 = s->begin_lst;
	p2 = NULL;
	if (p1)
		p2 = p1->next;
	while (p2)
	{
		if (!p2->live)
		{
			p1->next = p2->next;
			ft_free_process(p2);
		}
		else
		{
			p1 = p1->next;
			p2->live = 0;
		}
		p2 = p1->next;
	}
}

void		ft_win(t_stock *s)
{
	int		i;

	i = -1;
	if (!s->begin_lst)
	{
		while (++i < s->nb_player)
			if (s->last_champ_live == s->champ[i]->nb_player)
			{
				ft_putstr_v(s, s->champ[i]->header->prog_name);
				ft_putstr_v(s, " is the winner\n");
				if (s->opt_v)
					ft_print_winner(s, i);
				i = MAX_PLAYERS + 1;
			}
		if (i <= MAX_PLAYERS + 1)
		{
			ft_putstr_v(s, s->champ[0]->header->prog_name);
			ft_putstr_v(s, " is the winner\n");
			if (s->opt_v)
				ft_print_winner(s, 0);
		}
		s->cycle = -1;
	}
}

void		ft_cycle_to_die(t_stock *s)
{
	int			i;

	i = -1;
	if (s->check_max == 9 || s->total_nbr_live > NBR_LIVE)
	{
		s->check_max = -1;
		s->cycle_to_die -= CYCLE_DELTA;
	}
	s->check_max++;
	i = -1;
	while (++i < s->nb_player)
		s->champ[i]->live = 0;
	ft_clean_process(s);
	ft_win(s);
}
