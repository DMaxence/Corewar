/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/20 19:58:57 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static int				parse_add_type(char *opc, char *lab, char *line,
		t_asm *prog)
{
	static int			open_lab = 0;
	int					i;

	i = 0;
	if (lab != NULL)
	{
		if ((i = new_lab(lab, prog)) == 0)
			return (0);
		open_lab = 1;
		return (i);
	}
	if (open_lab == 0 || prog->line == 0)
		i = new_opc(opc, line, prog);
	else
	{
		if ((i = fill_opc(opc, line, prog)) == 0)
			return (0);
	}
	open_lab = 0;
	return (i);
}

static int				get_new_pro(char *line, char *word, t_asm *prog)
{
	int					i;
	char				*lab;
	char				*opc;

	lab = NULL;
	opc = NULL;
	if (ft_strnchar(LABEL_CHAR, word) != 0)
		lab = ft_strcdup(word, LABEL_CHAR);
	else
		opc = ft_strdup(word);
	i = parse_add_type(opc, lab, line, prog);
	if (opc != NULL)
		ft_strdel(&opc);
	if (lab != NULL)
		ft_strdel(&lab);
	return (i);
}

static int				check_opc(char *line, char *word, t_asm *prog)
{
	int					i;
	char				*args;

	i = 0;
	if (!(args = ft_strcdup(word, DIRECT_CHAR)))
		return (0);
	while (g_op_tab[i].opcode != 0)
	{
		if (ft_strcmp(args, g_op_tab[i].instruction) == 0)
		{
			if (ft_strnchar(SEPARATOR_CHAR, line) != g_op_tab[i].nb_param - 1)
				prog->err.code = ARG_ERR;
			else
				i = get_new_pro(line, args, prog);
			ft_strdel(&args);
			return (i);
		}
		i++;
	}
	prog->err.code = OPC_ERR;
	ft_strdel(&args);
	return (i);
}

static int				check_label(char *line, char *word, t_asm *prog)
{
	int					i;
	char				*lab;

	i = 0;
	if (ft_strnchar(LABEL_CHAR, word) != 0)
	{
		while (line[i] != LABEL_CHAR)
		{
			if (ft_strnchar(line[i], LABEL_CHARS) == 0)
			{
				if (line[i] != DIRECT_CHAR)
					prog->err.code = LAB_ERR;
				return (0);
			}
			i++;
		}
		if (i > 1)
		{
			lab = ft_strndup(word, i + 1);
			i = get_new_pro(line, lab, prog);
			ft_strdel(&lab);
			i += ft_count_white(line + i);
		}
	}
	return (i);
}

void					fill_pro(char *line, t_asm *prog)
{
	int					i;
	char				*word;
	char				*args;

	word = ft_strwdup(line);
	i = check_label(line, word, prog);
	ft_strdel(&word);
	if (prog->err.code != NO_ERR || !line[i] || line[i] == COMMENT_CHAR)
		return ;
	args = ft_strcdup(line + i, COMMENT_CHAR);
	word = ft_strwdup(args);
	if (args && word)
	{
		i += check_opc(args, word, prog);
		ft_strdel(&word);
		ft_strdel(&args);
	}
}
