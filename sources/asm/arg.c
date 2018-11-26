/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 15:55:19 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static int				check_label(char *arg, t_asm *prog)
{
	int					i;
	int					j;

	i = 0;
	j = 0;
	while (arg[j])
	{
		if (ft_strnchar(arg[j], LABEL_CHARS) == 0)
			return (1);
		j++;
	}
	while (i < prog->line)
	{
		if (prog->pro[i].lab && ft_strcmp(arg, prog->pro[i].lab) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int				check(char *arg, int i, t_asm *prog)
{
	if (arg[i] == LABEL_CHAR)
		return (check_label(arg + i + 1, prog));
	else if ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == '-')
	{
		if (arg[i] == '-')
			i++;
		if (!arg[i] || arg[i] < '0' || arg[i] > '9')
			return (1);
		while (arg[i] && arg[i] >= '0' && arg[i] <= '9')
			i++;
		if (arg[i])
			return (1);
	}
	else
		return (1);
	return (0);
}

int						dir_arg(char *arg, int mod, t_asm *prog)
{
	int					i;
	int					ret;

	i = 1;
	ret = 1;
	if (mod != T_DIR && mod != (T_DIR + T_REG) && mod != (T_DIR + T_IND)
		&& mod != (T_DIR + T_IND + T_REG))
		return (0);
	if (arg[i] && (ft_strnchar(arg[i], LABEL_CHARS) != 0
		|| arg[i] == LABEL_CHAR || arg[i] == '-'))
		ret = check(arg, i, prog);
	else
		return (0);
	if (ret)
		return (0);
	return (T_DIR);
}

int						ind_arg(char *arg, int mod, t_asm *prog)
{
	int					i;
	int					ret;

	i = 0;
	ret = 1;
	if (mod != T_IND && mod != (T_IND + T_DIR) && mod != (T_IND + T_REG)
		&& mod != (T_IND + T_DIR + T_REG))
		return (0);
	if (arg[i] && (ft_strnchar(arg[i], LABEL_CHARS) != 0
		|| arg[i] == LABEL_CHAR || arg[i] == '-'))
		ret = check(arg, i, prog);
	else
		return (0);
	if (ret)
		return (0);
	return (T_IND);
}

int						reg_arg(char *arg, int mod)
{
	int					i;
	int					reg;

	i = 1;
	if ((mod != T_REG && mod != (T_REG + T_DIR) && mod != (T_REG + T_IND)
		&& mod != (T_REG + T_DIR + T_IND)) || !arg[i])
		return (0);
	if (arg[i] < '0' || arg[i] > '9' || ft_strlen(arg + i) > 2)
		return (0);
	reg = ft_atoi(arg + i);
	if (reg > REG_NUMBER || reg == 0)
		return (0);
	return (T_REG);
}
