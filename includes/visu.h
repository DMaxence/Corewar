/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:08:16 by maduhoux          #+#    #+#             */
/*   Updated: 2018/11/20 19:55:07 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# include "corewar.h"
# include <ncurses.h>
# include <unistd.h>
# define BG					' '
# define BG_PAIR			5
# define MEMORY_PAIR		6
# define TEXT_PAIR			8
# define COLOR_DARK_GREY	10
# define COLOR_LIGHT_GREEN	11
# define COLOR_LIGHT_BLUE	12
# define COLOR_LIGHT_RED	13
# define COLOR_LIGHT_CYAN	14
# define BEGIN_DETAILS		199
# define END_DETAILS		251

void			draw_map(void);
void			ft_print_memory(t_stock *s);
void			ft_play_pause(t_stock *s);
void			ft_print_details(t_stock *s);
int				ft_print_cycles(t_stock *s, unsigned int y);
int				ft_print_live_breakdown(t_stock *s, unsigned int y);
void			ft_print_memory_in(t_stock *s);
void			ft_print_process_color(t_stock *s, char *tab);
void			ft_init_color(void);
int				ft_init_live_breakdown(unsigned int y);
int				ft_print_player(int y, int x, int i, t_stock *s);
void			ft_refresh_memory(t_stock *s);
void			ft_close_win(t_stock *s);
void			ft_print_process(t_process *lst, t_stock *s, unsigned int y);
void			ft_play(void);
void			ft_quit(t_stock *s);
void			ft_play_pause(t_stock *s);
t_process		*ft_key_right(t_process *lst, t_stock *s);
t_process		*ft_key_up(t_process *lst, t_stock *s);
void			ft_key_down(void);
int				ft_get_process_nb(t_stock *s);

#endif
