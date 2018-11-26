/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 16:00:46 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static int				write_arg(char *arg, int pos, t_asm *prog)
{
	int					i;
	int					ret;
	char				*word;

	ret = 0;
	word = ft_strwdup(arg);
	i = ft_strlen(word);
	i += ft_count_white(arg + i);
	if (arg[i])
	{
		ret = 1;
		prog->err.code = ARG_ERR;
	}
	else if (!(prog->pro[prog->line - 1].arg[pos].arg = ft_strdup(word)))
	{
		ret = 1;
		prog->err.code = MLC_ERR;
	}
	ft_strdel(&word);
	return (ret);
}

static int				fill_arg(char *opc, char *line, t_asm *prog)
{
	int					i;
	int					pos;
	char				*arg;

	arg = NULL;
	pos = 0;
	i = ft_strlen(opc);
	while (line[i] && i < (int)ft_strlen(line))
	{
		i += ft_count_white(line + i);
		if (!(arg = ft_strcdup(line + i, SEPARATOR_CHAR)))
		{
			prog->err.code = MLC_ERR;
			return (1);
		}
		if (write_arg(arg, pos, prog))
		{
			ft_strdel(&arg);
			return (1);
		}
		pos++;
		i += ft_strlen(arg) + 1;
		ft_strdel(&arg);
	}
	return (0);
}

static t_argu			*alloc_arg(int pos, t_asm *prog)
{
	int					i;
	t_argu				*ret;

	i = 0;
	if (!(ret = (t_argu *)malloc(sizeof(t_argu) *
		(prog->pro[pos].nb_arg + 1))))
		return (NULL);
	while (i <= prog->pro[pos].nb_arg)
	{
		ret[i].arg = NULL;
		i++;
	}
	return (ret);
}

int						fill_opc(char *opc, char *line, t_asm *prog)
{
	int					pos;
	char				*args;

	pos = prog->line - 1;
	args = ft_strcdup(line, COMMENT_CHAR);
	prog->pro[pos].nb_arg = ft_strnchar(SEPARATOR_CHAR, args) + 1;
	ft_strdel(&args);
	if ((prog->pro[pos].arg = alloc_arg(pos, prog)) == NULL)
		return (0);
	if ((prog->pro[pos].opc = ft_strdup(opc)) == NULL)
		return (0);
	args = ft_strcdup(line, COMMENT_CHAR);
	if (fill_arg(opc, args, prog))
	{
		ft_strdel(&args);
		return (0);
	}
	ft_strdel(&args);
	return (1);
}

int						new_opc(char *opc, char *line, t_asm *prog)
{
	int					i;

	i = 0;
	if (!(prog->pro = increase_pro(prog)))
		return (0);
	i = fill_opc(opc, line, prog);
	return (i);
}
