/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:07:37 by maduhoux          #+#    #+#             */
/*   Updated: 2018/11/19 11:19:48 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

static void		ft_init_misc_color(void)
{
	init_color(COLOR_DARK_GREY, 407, 407, 407);
	init_color(COLOR_LIGHT_GREEN, 376, 972, 360);
	init_color(COLOR_LIGHT_BLUE, 411, 447, 945);
	init_color(COLOR_LIGHT_RED, 1000, 407, 298);
	init_color(COLOR_LIGHT_CYAN, 376, 992, 1000);
	init_color(255, 1000, 1000, 1000);
	init_pair(BG_PAIR, COLOR_YELLOW, COLOR_DARK_GREY);
	init_pair(89, COLOR_BLACK, COLOR_YELLOW);
	init_pair(MEMORY_PAIR, COLOR_DARK_GREY, COLOR_BLACK);
	init_pair(TEXT_PAIR, 255, COLOR_BLACK);
}

void			ft_init_color(void)
{
	if (has_colors() == FALSE)
	{
		endwin();
		ft_printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	ft_init_misc_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(10, 255, COLOR_GREEN);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(20, 255, COLOR_BLUE);
	init_pair(22, COLOR_BLACK, COLOR_BLUE);
	init_pair(30, 255, COLOR_RED);
	init_pair(33, COLOR_BLACK, COLOR_RED);
	init_pair(40, 255, COLOR_CYAN);
	init_pair(44, COLOR_BLACK, COLOR_CYAN);
	init_pair(51, COLOR_LIGHT_GREEN, COLOR_BLACK);
	init_pair(52, COLOR_LIGHT_BLUE, COLOR_BLACK);
	init_pair(53, COLOR_LIGHT_RED, COLOR_BLACK);
	init_pair(54, COLOR_LIGHT_CYAN, COLOR_BLACK);
	clear();
}

void			draw_map(void)
{
	int		y;

	attron(COLOR_PAIR(BG_PAIR));
	mvhline(0, 0, BG, 253);
	mvhline(67, 0, BG, 253);
	y = -1;
	while (++y <= 67)
	{
		mvaddch(y, 0, BG);
		mvaddch(y, 196, BG);
		mvaddch(y, 253, BG);
	}
	attroff(COLOR_PAIR(BG_PAIR));
}

void			ft_close_win(t_stock *s)
{
	int			ch;
	t_process	*lst;
	t_process	*lst_tmp;

	lst = s->begin_lst;
	lst_tmp = s->begin_lst;
	if (s->opt_v)
	{
		while ((ch = getch()) && (ch != 'q') && (ch != 'Q') && s->running > -1)
		{
			if (ch == 261)
				lst = ft_key_right(lst, s);
			else if (ch == 259)
				lst = ft_key_up(s->begin_lst, s);
			else if (ch == 258)
				ft_key_down();
			refresh();
		}
		endwin();
	}
}

int				ft_init_live_breakdown(unsigned int y)
{
	unsigned int	x;

	x = BEGIN_DETAILS;
	attron(COLOR_PAIR(TEXT_PAIR));
	mvprintw(y++, x, "Live breakdown for current period :");
	attron(COLOR_PAIR(MEMORY_PAIR));
	attroff(COLOR_PAIR(TEXT_PAIR));
	attron(COLOR_PAIR(MEMORY_PAIR));
	mvprintw(y, x, "[--------------------------------------------------]");
	y += 2;
	attroff(COLOR_PAIR(MEMORY_PAIR));
	attron(COLOR_PAIR(TEXT_PAIR));
	mvprintw(y++, x, "Live breakdown for last period :");
	attroff(COLOR_PAIR(TEXT_PAIR));
	attron(COLOR_PAIR(MEMORY_PAIR));
	mvprintw(y, x, "[--------------------------------------------------]");
	attroff(COLOR_PAIR(MEMORY_PAIR));
	return (y + 2);
}
