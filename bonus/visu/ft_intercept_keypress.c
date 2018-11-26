/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intercept_keypress.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:44:19 by maduhoux          #+#    #+#             */
/*   Updated: 2018/11/19 11:20:11 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

void		ft_play(void)
{
	mvprintw(2, BEGIN_DETAILS, "** RUNNING **");
	attroff(COLOR_PAIR(TEXT_PAIR));
	nodelay(stdscr, TRUE);
}

void		ft_quit(t_stock *s)
{
	nodelay(stdscr, TRUE);
	attroff(COLOR_PAIR(TEXT_PAIR));
	s->cycle = -1;
	s->running = -1;
	endwin();
}

void		ft_play_pause(t_stock *s)
{
	int			ch;
	t_process	*lst;

	nodelay(stdscr, FALSE);
	attron(COLOR_PAIR(TEXT_PAIR));
	mvprintw(2, BEGIN_DETAILS, "** PAUSED ** ");
	lst = s->begin_lst;
	while ((ch = getch()) && (ch != 'q') && (ch != 'Q'))
	{
		if (ch == ' ')
		{
			ft_play();
			break ;
		}
		else if (ch == 261)
			lst = ft_key_right(lst, s);
		else if (ch == 259)
			lst = ft_key_up(s->begin_lst, s);
		else if (ch == 258)
			ft_key_down();
		refresh();
	}
	if (ch == 'q')
		ft_quit(s);
}
