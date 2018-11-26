/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sidebar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:12:18 by maduhoux          #+#    #+#             */
/*   Updated: 2018/11/22 13:54:57 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

void	ft_print_details(t_stock *s)
{
	unsigned int		x;
	unsigned int		y;
	int					i;

	attron(COLOR_PAIR(TEXT_PAIR));
	x = BEGIN_DETAILS;
	y = 2;
	mvprintw(y, x, "** RUNNING **");
	y += 2;
	mvprintw(y, x, "Cycles/second limit : %d   ", CYCLE_SECOND_LIMIT);
	y += 3;
	mvprintw(y, x, "Cycle : %d          ", s->cycle);
	y += 2;
	mvprintw(y, x, "Processes : %d          ", ft_get_process_nb(s));
	y += 2;
	i = 1;
	while (i <= s->nb_player)
	{
		y = ft_print_player(y, x, i, s);
		++i;
	}
	attroff(COLOR_PAIR(TEXT_PAIR));
	y = (s->cycle == 0) ? ft_init_live_breakdown(y) : \
	ft_print_live_breakdown(s, y + 1);
	y = ft_print_cycles(s, y);
}

int		ft_print_player(int y, int x, int i, t_stock *s)
{
	mvprintw(y, x, "Player -%d :", i);
	attroff(COLOR_PAIR(TEXT_PAIR));
	attron(COLOR_PAIR(i + 50));
	mvprintw(y++, x + 12, "%.41s", s->champ[i - 1]->header->prog_name);
	attroff(COLOR_PAIR(i + 50));
	attron(COLOR_PAIR(TEXT_PAIR));
	mvprintw(y++, x + 2, "Last live : \t\t\t %d             ", \
	s->champ[i - 1]->last_live[i - 1]);
	mvprintw(y++, x + 2, "Lives in current period : \t %d       ", \
	s->champ[i - 1]->live);
	y++;
	return (y);
}

void	ft_print_player_live_breakdown(t_stock *s, int lives, int y)
{
	int				compt;
	int				x;
	int				i;

	i = 0;
	x = BEGIN_DETAILS + 1;
	while (++i <= s->nb_player)
	{
		compt = -1;
		attron(COLOR_PAIR(i));
		if (lives > 0)
		{
			while (++compt < ((50 * s->champ[i - 1]->live) / lives) \
			&& x < BEGIN_DETAILS + 50)
				mvprintw(y, x++, "-");
			if (compt < 50 && s->champ[i - 1]->live > 0)
				mvprintw(y, x++, "-");
		}
		attroff(COLOR_PAIR(i));
	}
}

int		ft_print_live_breakdown(t_stock *s, unsigned int y)
{
	int				i;
	int				lives;

	i = -1;
	lives = 0;
	while (++i < s->nb_player)
		lives += s->champ[i]->live;
	if (s->cycle && s->cycle % s->cycle_to_die == 0)
		y += 3;
	ft_print_player_live_breakdown(s, lives, y);
	attron(COLOR_PAIR(MEMORY_PAIR));
	mvprintw(y, BEGIN_DETAILS + 51, "]  ");
	attroff(COLOR_PAIR(MEMORY_PAIR));
	if (s->cycle == 0 || s->cycle % s->cycle_to_die != 0)
		y += 3;
	return (y + 2);
}

int		ft_print_cycles(t_stock *s, unsigned int y)
{
	unsigned int		x;

	attron(COLOR_PAIR(TEXT_PAIR));
	x = BEGIN_DETAILS;
	mvprintw(y, x, "CYCLE_TO_DIE : %d ", s->cycle_to_die);
	y += 2;
	mvprintw(y, x, "CYCLE_DELTA : %d", CYCLE_DELTA);
	y += 2;
	mvprintw(y, x, "NBR_LIVE : %d", NBR_LIVE);
	y += 2;
	mvprintw(y, x, "MAX_CHECKS : %d", MAX_CHECKS);
	y += 2;
	attroff(COLOR_PAIR(TEXT_PAIR));
	return (y);
}
