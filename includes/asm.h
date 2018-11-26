/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:43:02 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 16:42:50 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include "../libft/lib_asm/includes/libft.h"
# include "../libft/lib_asm/includes/ft_printf.h"
# include "op.h"

# define COM_CMD_STRING			".comment"
# define NAME_CMD_STRING		".name"

typedef struct					s_op
{
	const char					*instruction;
	int							nb_param;
	unsigned int				arg_mod[3];
	int							opcode;
	int							exec_time;
	const char					*def;
	int							oct_cod;
	int							haveindex;
}								t_op;

typedef enum					e_ernum
{
	ARG_ERR,
	CRT_FAIL,
	ERR_CLOSE,
	ERR_OPEN,
	ERR_TYPE,
	ETY_FILE,
	HEAD_ERR,
	LAB_ERR,
	MLC_ERR,
	NO_PRO,
	OPC_ERR,
	PRO_ERR,
	PROG_SIZE,
	SIZE_COM,
	SIZE_NAME,
	STX_ERR,
	NO_ERR,
}								t_ernum;

typedef struct					s_err
{
	t_ernum						code;
	char						*msg;
}								t_err;

typedef struct					s_argu
{
	int							type;
	char						*arg;
}								t_argu;

typedef struct					s_pro
{
	char						*lab;
	char						*opc;
	int							nb_arg;
	t_argu						*arg;
}								t_pro;

typedef struct					s_param
{
	int							noct;
	int							val;
}								t_param;

typedef struct					s_byte
{
	int							inst;
	int							oct;
	t_param						*param;
	int							nb_oct;
}								t_byte;

typedef struct					s_asm
{
	int							fd;
	t_err						err;
	t_header					head;
	int							line;
	t_pro						*pro;
	t_byte						*byte;
	int							cor_size;
	int							i;
	char						*cor;
}								t_asm;

t_op							g_op_tab[17];
t_err							g_out[17];

void							conv_file(char *file, t_asm *prog);
void							print_err(char *file, t_asm *prog);
void							create_cor(char *file, t_asm *prog);
void							free_prog(t_asm *prog);

void							fill_header(char *line, int i, t_asm *prog);
void							fill_pro(char *line, t_asm *prog);
void							check_pro(t_asm *prog);
void							translate(t_asm *prog);
int								head_step(t_asm *prog);
int								byte_step(t_asm *prog);

int								new_lab(char *lab, t_asm *prog);
int								new_opc(char *opc, char *line, t_asm *prog);
int								fill_opc(char *opc, char *line, t_asm *prog);

t_pro							*increase_pro(t_asm *prog);

int								reg_arg(char *arg, int mod);
int								dir_arg(char *arg, int mod, t_asm *prog);
int								ind_arg(char *arg, int mod, t_asm *prog);

int								fill_byte(int pos, t_asm *prog);
int								fill_jump(t_asm *prog);

#endif
