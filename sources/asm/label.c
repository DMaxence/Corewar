/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/11/13 16:00:28 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int						new_lab(char *lab, t_asm *prog)
{
	int					pos;

	if (!(prog->pro = increase_pro(prog)))
		return (0);
	pos = prog->line - 1;
	if ((prog->pro[pos].lab = ft_strdup(lab)) == NULL)
	{
		prog->err.code = MLC_ERR;
		return (0);
	}
	return (ft_strlen(lab) + 1);
}
