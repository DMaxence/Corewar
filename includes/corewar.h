/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:48:12 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/21 19:12:49 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/lib_vm/header/libft.h"
# include "struct.h"
# include <fcntl.h>
# include <unistd.h>
# include "op.h"

# define CYCLE_SECOND_LIMIT 50

/*
**	-------------------------  STRUCT PART  -----------------------------------
*/
typedef struct			s_process
{
	int					registre[REG_NUMBER];
	short				carry;
	short				wait;
	int					pc;
	int					old_pc;
	int					live;
	int					id;
	char				*aff;
	struct s_process	*next;
}						t_process;

/*
**	Structure d'un champion (une pour chaque)
**	nb_player = numero du joueur;
**	wait = nombre de cycles avant execution de l'instruction;
**	pc = process counter nombre de cases entre le debut du programme
**		et le processus courant
*/
typedef struct			s_champ
{
	t_header			*header;
	int					live;
	int					last_live[4];
	int					nb_player;
}						t_champ;

/*
**	Structure contenant les donnees utiles a un code couleur. -maduhoux
*/
typedef struct			s_color
{
	int					rgb;
	int					cycle;
	int					player;
	int					time_to_live;
}						t_color;

/*
**	Structure contenant toutes les infos utiles. -anaroste
*/
typedef struct			s_stock
{
	char				memory[MEM_SIZE];
	t_color				rgb[MEM_SIZE];
	int					opt_dump;
	char				opt_v;
	char				opt_a;
	int					running;
	int					cycle;
	int					cycle_to_die;
	int					check_max;
	int					total_nbr_live;
	int					last_champ_live;
	short				nb_player;
	t_champ				**champ;
	t_process			*begin_lst;
}						t_stock;

/*
**	--------------------------  READ PART  ------------------------------------
*/
void					ft_free_memory(t_stock *s);
int						check_flag(int ac, char **av, t_stock *s);
int						ft_new_player(char *str, t_stock *s);
int						ft_new_process(short pc, int r1, t_stock *s);
int						ft_read_champs(int ac, char **av, t_stock *s);
int						ft_arrange_player(int ac, char **av, t_stock *s);
/*
**	ft_player_tools.c
*/
void					ft_change_process(int before, int new_nb, t_stock *s);
void					ft_init_tab(int (*tab)[MAX_PLAYERS][2]);

/*
**	--------------------------  EXEC PART  ------------------------------------
*/
t_stock					*ft_init_and_read(int ac, char **av, t_stock *s);
void					ft_free_memory(t_stock *s);
char					translate_ocp(char ocp, int arg);
int						read_direct(int to_read, t_stock *s, t_process *p,
						int start);
int						read_index(t_stock *s, t_process *p, int start,
						char idx);
int						ft_index_pc(int index, int pc);
int						ft_idx(int index);
int						ft_verif_reg(int registre);
int						ft_change_vm_zaz(int nb);
void					ft_putstr_v(t_stock *s, char *str);
void					ft_putnbr_v(t_stock *s, int nb);
void					write_nb(t_stock *s, int start, int nb);
void					write_nb_rgb(t_stock *s, int start, int champ);
void					write_str(t_stock *s, int start, char *str,
						int length);
void					write_index(t_stock *s, int start, int nb);
void					write_idx(t_stock *s, t_process *p, int index,
						int nb);
void					write_idx_rgb(t_stock *s, t_process *p, int index,
						int c);
int						ft_execute_instruction(t_stock *s, t_process *p);
void					ft_next_instruction(t_stock *s, t_process *p,
						char inst);
void					ft_first_play(t_stock *s);
void					ft_print_dump(t_stock *s);
int						ft_execution(t_stock *s);
void					ft_wait_instruction(t_process *p, char inst);
void					ft_print_memory(t_stock *s);
void					ft_cycle_to_die(t_stock *s);

int						ft_live(t_stock *s, t_process *p);
int						ft_ld(t_stock *s, t_process *p);
int						ft_st(t_stock *s, t_process *p);
int						ft_add(t_stock *s, t_process *p);
int						ft_sub(t_stock *s, t_process *p);
int						ft_and(t_stock *s, t_process *p);
int						ft_or(t_stock *s, t_process *p);
int						ft_xor(t_stock *s, t_process *p);
int						ft_zjmp(t_stock *s, t_process *p);
int						ft_ldi(t_stock *s, t_process *p);
int						ft_sti(t_stock *s, t_process *p);
int						ft_fork(t_stock *s, t_process *p);
int						ft_lld(t_stock *s, t_process *p);
int						ft_lldi(t_stock *s, t_process *p);
int						ft_lfork(t_stock *s, t_process *p);
int						ft_aff(t_stock *s, t_process *p);

/*
**	--------------------------  VISU PART  ------------------------------------
*/
void					ft_print_winner(t_stock *s, int i);

#endif
