/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 16:00:20 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static int				get_diff(int start, int end, int neg, t_asm *prog)
{
	int					ret;

	ret = 0;
	while (start < end)
	{
		ret += prog->byte[start].nb_oct;
		start++;
	}
	return (ret * neg);
}

static int				get_jump(int line, char *lab, t_asm *prog)
{
	int					i;
	int					ret;

	i = 0;
	ret = 0;
	while (i < prog->line)
	{
		if (ft_strcmp(lab, prog->pro[i].lab) == 0 && i < line)
			return (get_diff(i, line, -1, prog));
		else if (ft_strcmp(lab, prog->pro[i].lab) == 0 && i > line)
			return (get_diff(line, i, 1, prog));
		else if (ft_strcmp(lab, prog->pro[i].lab) == 0 && i == line)
			break ;
		i++;
	}
	return (0);
}

int						fill_jump(t_asm *prog)
{
	int					i;
	int					j;

	i = 0;
	while (i < prog->line)
	{
		j = 0;
		while (j < prog->pro[i].nb_arg)
		{
			if (ft_strnchar(LABEL_CHAR, prog->pro[i].arg[j].arg) != 0)
			{
				if (prog->pro[i].arg[j].arg[0] == DIRECT_CHAR)
					prog->byte[i].param[j].val = get_jump(i,
					prog->pro[i].arg[j].arg + 2, prog);
				else
					prog->byte[i].param[j].val = get_jump(i,
					prog->pro[i].arg[j].arg + 1, prog);
			}
			j++;
		}
		i++;
	}
	return (0);
}
