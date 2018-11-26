/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 15:59:29 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void			free_arg_param(int i, t_asm *prog)
{
	int				j;

	j = 0;
	while (j < prog->pro[i].nb_arg)
	{
		if (prog->pro[i].arg[j].arg != NULL)
			ft_strdel(&prog->pro[i].arg[j].arg);
		j++;
	}
	free(prog->pro[i].arg);
	prog->pro[i].arg = NULL;
	if (prog->byte)
	{
		free(prog->byte[i].param);
		prog->pro[i].arg = NULL;
	}
}

static void			free_pro_byte(t_asm *prog)
{
	int				i;

	i = 0;
	while (i < prog->line)
	{
		if (prog->pro[i].lab != NULL)
			ft_strdel(&prog->pro[i].lab);
		if (prog->pro[i].opc != NULL)
			ft_strdel(&prog->pro[i].opc);
		if (prog->pro[i].nb_arg > 0)
			free_arg_param(i, prog);
		i++;
	}
}

void				free_prog(t_asm *prog)
{
	free_pro_byte(prog);
	if (prog->pro)
	{
		free(prog->pro);
		prog->pro = NULL;
	}
	if (prog->byte)
	{
		free(prog->byte);
		prog->byte = NULL;
	}
	if (prog->err.msg != NULL)
		ft_strdel(&prog->err.msg);
	if (prog->cor != NULL)
		ft_strdel(&prog->cor);
}
