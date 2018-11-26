/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 16:01:08 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void				init_ret(t_pro *ret)
{
	ret[0].lab = NULL;
	ret[0].opc = NULL;
	ret[0].nb_arg = 0;
	ret[0].arg = NULL;
	ret[1].lab = NULL;
	ret[1].opc = NULL;
	ret[1].nb_arg = 0;
	ret[1].arg = NULL;
}

static t_argu			*cpy_arg(int i, int nb, t_pro *pro)
{
	int					j;
	t_argu				*ret;

	j = 0;
	ret = NULL;
	if (!(ret = (t_argu *)malloc(sizeof(t_argu) * nb + 1)))
		return (NULL);
	while (j < nb)
	{
		ret[j].arg = ft_strdup(pro[i].arg[j].arg);
		ft_strdel(&(pro[i].arg[j].arg));
		j++;
	}
	free(pro[i].arg);
	ret[j].arg = NULL;
	return (ret);
}

static int				cpy_opc_and_lab(int i, t_pro *ret, t_pro *pro)
{
	if (pro[i].lab != NULL)
	{
		if (!(ret[i].lab = ft_strdup(pro[i].lab)))
			return (0);
		ft_strdel(&pro[i].lab);
	}
	else
		ret[i].lab = NULL;
	if (pro[i].opc != NULL)
	{
		if (!(ret[i].opc = ft_strdup(pro[i].opc)))
			return (0);
		ft_strdel(&pro[i].opc);
	}
	else
		ret[i].opc = NULL;
	return (1);
}

static t_pro			*cpy_pro(int line, t_pro *pro)
{
	int					i;
	t_pro				*ret;

	i = 0;
	if (!(ret = (t_pro *)malloc(sizeof(t_pro) * (line + 2))))
		return (NULL);
	while (i < line)
	{
		if (!(cpy_opc_and_lab(i, ret, pro)))
			return (NULL);
		ret[i].nb_arg = pro[i].nb_arg;
		if (ret[i].nb_arg && !(ret[i].arg = cpy_arg(i, ret[i].nb_arg, pro)))
			return (NULL);
		i++;
	}
	free(pro);
	pro = NULL;
	ret[i].lab = NULL;
	ret[i].opc = NULL;
	ret[i].nb_arg = 0;
	return (ret);
}

t_pro					*increase_pro(t_asm *prog)
{
	t_pro				*ret;

	ret = NULL;
	if (prog->line == 0)
	{
		if (!(ret = (t_pro *)malloc(sizeof(t_pro) * 2)))
		{
			prog->err.code = MLC_ERR;
			return (NULL);
		}
		init_ret(ret);
	}
	else if (!(ret = cpy_pro(prog->line, prog->pro)))
	{
		prog->err.code = MLC_ERR;
		return (NULL);
	}
	prog->line++;
	return (ret);
}
