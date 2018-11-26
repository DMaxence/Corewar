/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:39:03 by maduhoux          #+#    #+#             */
/*   Updated: 2018/11/20 19:23:42 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

static void		ft_print_process_in(t_stock *s, t_process *lst)
{
	char				*tab;

	tab = "0123456789abcdef";
	ft_print_process_color(s, tab);
	attron(COLOR_PAIR(89));
	mvaddch((lst->pc / 64) + 2, ((lst->pc % 64) * 3) + 3, \
		tab[(s->memory[lst->pc] >> 4) & 0x0f]);
	mvaddch((lst->pc / 64) + 2, ((lst->pc % 64) * 3) + 4, \
		tab[s->memory[lst->pc] & 0x0f]);
	attroff(COLOR_PAIR(89));
}

void			ft_print_process(t_process *lst, t_stock *s, unsigned int y)
{
	unsigned int		x;
	unsigned int		tmpy;

	tmpy = y + 1;
	attron(COLOR_PAIR(TEXT_PAIR));
	x = BEGIN_DETAILS;
	mvprintw(y, x, "/************** PROCESS **************/");
	if (lst)
	{
		while (++y < tmpy + 16)
			mvprintw(y, x + 2, "registre[%d]: %d               ", \
			(y - tmpy), lst->registre[y - tmpy]);
		y++;
		mvprintw(y, x + 2, "CARRY : %hi          ", lst->carry);
		y++;
		mvprintw(y, x + 2, "PC : %d             ", lst->pc);
		y++;
		mvprintw(y, x + 2, "ID : %d               ", lst->id);
		y++;
		mvprintw(y, x + 2, "WAIT : %hi", lst->wait);
		ft_print_process_in(s, lst);
	}
	attroff(COLOR_PAIR(TEXT_PAIR));
}

int				ft_get_process_nb(t_stock *s)
{
	t_process	*lst;
	int			i;

	lst = s->begin_lst;
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void			ft_print_winner(t_stock *s, int i)
{
	int		x;
	int		y;

	x = BEGIN_DETAILS;
	y = (s->nb_player * 4) + 27;
	attron(COLOR_PAIR(TEXT_PAIR));
	mvprintw(y + 2, x, "Press key 'q' to exit");
	mvprintw(y, x, "The winner is : ");
	attroff(COLOR_PAIR(TEXT_PAIR));
	attron(COLOR_PAIR(i + 1 + 50));
	mvprintw(y, x + 16, "%s    ", s->champ[i]->header->prog_name);
	attroff(COLOR_PAIR(i + 1 + 50));
}
