/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:10:17 by anaroste          #+#    #+#             */
/*   Updated: 2018/11/02 16:06:45 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/corewar.h"

void			write_nb(t_stock *s, int start, int nb)
{
	s->memory[(start + 3) % MEM_SIZE] = (nb & 0x000000ff);
	s->memory[(start + 2) % MEM_SIZE] = ((nb & 0x0000ff00) >> 8);
	s->memory[(start + 1) % MEM_SIZE] = ((nb & 0x00ff0000) >> 16);
	s->memory[(start + 0) % MEM_SIZE] = ((nb & 0xff000000) >> 24);
}

void			write_nb_rgb(t_stock *s, int start, int champ)
{
	s->rgb[(start + 3) % MEM_SIZE].rgb = champ + 50;
	s->rgb[(start + 3) % MEM_SIZE].player = champ;
	s->rgb[(start + 3) % MEM_SIZE].cycle = s->cycle;
	s->rgb[(start + 3) % MEM_SIZE].time_to_live = 60;
	s->rgb[(start + 2) % MEM_SIZE].rgb = champ + 50;
	s->rgb[(start + 2) % MEM_SIZE].player = champ;
	s->rgb[(start + 2) % MEM_SIZE].cycle = s->cycle;
	s->rgb[(start + 2) % MEM_SIZE].time_to_live = 60;
	s->rgb[(start + 1) % MEM_SIZE].rgb = champ + 50;
	s->rgb[(start + 1) % MEM_SIZE].player = champ;
	s->rgb[(start + 1) % MEM_SIZE].cycle = s->cycle;
	s->rgb[(start + 1) % MEM_SIZE].time_to_live = 60;
	s->rgb[(start + 0) % MEM_SIZE].rgb = champ + 50;
	s->rgb[(start + 0) % MEM_SIZE].player = champ;
	s->rgb[(start + 0) % MEM_SIZE].cycle = s->cycle;
	s->rgb[(start + 0) % MEM_SIZE].time_to_live = 60;
}

void			write_index(t_stock *s, int start, int nb)
{
	int		index;

	index = 0;
	if ((start = start % MEM_SIZE) < 0)
		start += MEM_SIZE;
	index += s->memory[(start + 1) % MEM_SIZE];
	index += s->memory[(start + 0) % MEM_SIZE] << 8;
	write_nb(s, index, nb);
}

void			write_idx(t_stock *s, t_process *p, int index, int nb)
{
	write_nb(s, ft_index_pc(ft_idx(read_direct(2, s, p, index)), p->pc), nb);
}

void			write_idx_rgb(t_stock *s, t_process *p, int index, int c)
{
	write_nb_rgb(s, ft_index_pc(ft_idx(read_direct(2, s, p, index)), p->pc), c);
}
