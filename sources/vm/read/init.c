/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:02:27 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/21 14:47:59 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

static int		ft_init_champ(t_stock *s)
{
	int		i;

	if (!(s->champ = (t_champ **)malloc(sizeof(t_champ *) * MAX_PLAYERS)))
		return (0);
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (!(s->champ[i] = (t_champ *)malloc(sizeof(t_champ)))
				|| (!(s->champ[i]->header =
						(t_header *)malloc(sizeof(t_header)))))
			return (0);
		s->champ[i]->live = 0;
		s->champ[i]->last_live[i] = 0;
		s->champ[i]->nb_player = 0;
		s->champ[i]->header->magic = 0;
		s->champ[i]->header->prog_size = 0;
	}
	return (1);
}

static void		ft_init_var(t_stock *s)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		s->rgb[i].rgb = 0;
		s->rgb[i].player = 0;
		s->rgb[i].cycle = 0;
		s->rgb[i].time_to_live = 0;
	}
	s->check_max = 0;
	s->total_nbr_live = 0;
	s->last_champ_live = 1;
	s->opt_dump = -5;
	s->opt_v = 0;
	s->opt_a = 0;
	s->running = 1;
	s->cycle = 0;
	s->cycle_to_die = CYCLE_TO_DIE;
	s->nb_player = 0;
}

t_stock			*ft_init_and_read(int ac, char **av, t_stock *s)
{
	if (!(s = (t_stock *)malloc(sizeof(t_stock)))
		|| !ft_init_champ(s))
	{
		ft_putstr_fd("Error malloc\n", 2);
		ft_free_memory(s);
		return (NULL);
	}
	ft_bzero(s->memory, MEM_SIZE);
	ft_init_var(s);
	if (!check_flag(ac, av, s) || !ft_read_champs(ac, av, s))
	{
		ft_free_memory(s);
		return (NULL);
	}
	return (s);
}
