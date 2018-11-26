/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:37:29 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/22 12:25:18 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

void		ft_print_memory_in(t_stock *s)
{
	unsigned int		i;
	unsigned int		x;
	unsigned int		begin;
	unsigned int		player;

	i = -1;
	x = 0;
	player = 0;
	while (++i < MEM_SIZE)
	{
		begin = ((MEM_SIZE / s->nb_player) * player);
		if (i >= begin && i < begin + s->champ[player]->header->prog_size)
		{
			x++;
			s->rgb[i].rgb = player + 1;
			s->rgb[i].player = player + 1;
			if (x == s->champ[player]->header->prog_size)
			{
				x = 0;
				player++;
			}
		}
	}
}

void		ft_print_process_color(t_stock *s, char *tab)
{
	t_process			*p;

	p = s->begin_lst;
	while (p)
	{
		attron(COLOR_PAIR(p->id * 11));
		mvaddch((p->pc / 64) + 2, ((p->pc % 64) * 3) + 3, \
			tab[(s->memory[p->pc] >> 4) & 0x0f]);
		mvaddch((p->pc / 64) + 2, ((p->pc % 64) * 3) + 4, \
			tab[s->memory[p->pc] & 0x0f]);
		attroff(COLOR_PAIR(p->id * 11));
		p = p->next;
	}
}

void		ft_print_memory_color(t_stock *s, char *tab)
{
	int					i;
	int					color;
	unsigned int		x;
	unsigned int		y;

	i = -1;
	y = 2;
	x = 3;
	while (++i < MEM_SIZE)
	{
		y = (x == 195) ? y + 1 : y;
		x = (x == 195) ? 3 : x;
		if (s->rgb[i].rgb > 0)
			color = ((s->cycle - s->rgb[i].cycle) <= s->rgb[i].time_to_live) \
			? s->rgb[i].rgb : s->rgb[i].player;
		else
			color = MEMORY_PAIR;
		attron(COLOR_PAIR(color));
		mvaddch(y, x++, tab[(s->memory[i] >> 4) & 0x0f]);
		mvaddch(y, x++, tab[s->memory[i] & 0x0f]);
		attroff(COLOR_PAIR(color));
		mvaddch(y, x++, ' ');
	}
	ft_print_process_color(s, tab);
}

void		ft_print_memory(t_stock *s)
{
	char	*tab;

	tab = "0123456789abcdef";
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	ft_init_color();
	draw_map();
	ft_print_memory_in(s);
	ft_print_memory_color(s, tab);
	ft_print_details(s);
	ft_play_pause(s);
}

void		ft_refresh_memory(t_stock *s)
{
	char	*tab;
	int		ch;

	tab = "0123456789abcdef";
	ft_print_memory_color(s, tab);
	ft_print_details(s);
	ch = getch();
	if (ch == ' ')
		ft_play_pause(s);
	if (ch == 'q')
	{
		s->cycle = -1;
		s->running = -1;
		endwin();
	}
	if (CYCLE_SECOND_LIMIT <= 0 || CYCLE_SECOND_LIMIT > 750000)
		ch = 15000;
	else
		ch = (1 / (float)CYCLE_SECOND_LIMIT) * 750000;
	usleep(ch);
	refresh();
}
